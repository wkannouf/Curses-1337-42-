#!/bin/bash

set -e

DB_PASSWORD=$(cat /run/secrets/db_password)

echo "Waiting for MariaDB..."

database_ready=false
for attempt in $(seq 1 30); do
    if mysql -h mariadb -u"$MYSQL_USER" -p"$DB_PASSWORD" -e "SELECT 1;" >/dev/null 2>&1; then
        database_ready=true
        break
    fi
    sleep 2
done

if [ "$database_ready" != true ]; then
    echo "MariaDB did not become available in time." >&2
    exit 1
fi

echo "MariaDB is ready."

cd /var/www/html

if [ ! -f wp-load.php ]; then
    wp core download --allow-root

    wp config create \
        --dbname="$MYSQL_DATABASE" \
        --dbuser="$MYSQL_USER" \
        --dbpass="$DB_PASSWORD" \
        --dbhost="mariadb:3306" \
        --allow-root

    wp core install \
        --url="https://$DOMAIN_NAME" \
        --title="Inception" \
        --admin_user="$WP_ADMIN_USER" \
        --admin_password="$(cat /run/secrets/wp_admin_password)" \
        --admin_email="$WP_ADMIN_EMAIL" \
        --skip-email \
        --allow-root

    wp user create \
    wissal \
    wissal@wkannouf.42.fr \
    --role=subscriber \
    --user_pass="$(cat /run/secrets/wp_user_password)" \
    --allow-root

    chown -R www-data:www-data /var/www/html
fi

exec php-fpm8.2 -F
