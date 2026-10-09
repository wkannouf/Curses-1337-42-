#!/bin/bash

set -e

mkdir -p /run/mysqld
chown mysql:mysql /run/mysqld
chown -R mysql:mysql /var/lib/mysql

DB_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)
DB_PASSWORD=$(cat /run/secrets/db_password)

case "$MYSQL_DATABASE" in
    ''|*[!a-zA-Z0-9_]* )
        echo "MYSQL_DATABASE must contain only letters, numbers, and underscores." >&2
        exit 1
        ;;
esac

case "$MYSQL_USER" in
    ''|*[!a-zA-Z0-9_]* )
        echo "MYSQL_USER must contain only letters, numbers, and underscores." >&2
        exit 1
        ;;
esac

sql_escape() {
    printf '%s' "$1" | sed "s/'/''/g"
}

DB_ROOT_PASSWORD_SQL=$(sql_escape "$DB_ROOT_PASSWORD")
DB_PASSWORD_SQL=$(sql_escape "$DB_PASSWORD")

init_marker="/var/lib/mysql/.inception_initialized"

if [ ! -f "$init_marker" ]; then
    if [ ! -d "/var/lib/mysql/mysql" ]; then
        mysql_install_db --user=mysql --datadir=/var/lib/mysql
    fi

    mysqld --user=mysql --skip-networking &
    MYSQL_PID=$!

    database_ready=false
    for attempt in $(seq 1 30); do
        if mariadb-admin ping --silent; then
            database_ready=true
            break
        fi
        sleep 1
    done

    if [ "$database_ready" != true ]; then
        echo "MariaDB initialization timed out." >&2
        exit 1
    fi

    mariadb -u root <<EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD_SQL}';
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD_SQL}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF

    mariadb -u "${MYSQL_USER}" -p"${DB_PASSWORD}" "${MYSQL_DATABASE}" -e 'SELECT 1;' >/dev/null

    mariadb-admin -u root -p"${DB_ROOT_PASSWORD}" shutdown
    wait "$MYSQL_PID"

    touch "$init_marker"
    chown mysql:mysql "$init_marker"
fi

exec mysqld --user=mysql --console
