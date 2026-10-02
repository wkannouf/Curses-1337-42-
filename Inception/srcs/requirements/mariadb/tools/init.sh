#!/bin/bash

set -e

mkdir -p /run/mysqld
chown mysql:mysql /run/mysqld
chown -R mysql:mysql /var/lib/mysql

DB_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)
DB_PASSWORD=$(cat /run/secrets/db_password)

if [ ! -d "/var/lib/mysql/mysql" ]; then
    mysql_install_db --user=mysql --datadir=/var/lib/mysql

    mysqld --user=mysql --skip-networking &
    MYSQL_PID=$!

    until mariadb-admin ping --silent; do
        sleep 1
    done

    mariadb -u root <<EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF

    mariadb-admin -u root -p"${DB_ROOT_PASSWORD}" shutdown
    wait $MYSQL_PID
fi

exec mysqld --user=mysql --console
