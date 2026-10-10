#!/bin/bash

set -eu

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

if [ ! -d "/var/lib/mysql/mysql" ]; then
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
fi

if [ ! -f "$init_marker" ]; then
    init_file=$(mktemp)
    chmod 600 "$init_file"
    chown mysql:mysql "$init_file"

    cat > "$init_file" <<EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD_SQL}';
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD_SQL}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
SELECT 'initialized' INTO OUTFILE '${init_marker}';
EOF

    exec mysqld --user=mysql --console --init-file="$init_file"
fi

exec mysqld --user=mysql --console
