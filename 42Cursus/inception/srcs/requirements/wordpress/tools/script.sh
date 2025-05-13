#!/bin/bash

until mysql -h mariadb -u ${MYSQL_USER} -p${MYSQL_PASSWORD} -e "SELECT 1" &>/dev/null; do
    sleep 2
done


chown -R www-data:www-data /var/www/html
mkdir -p /var/www/.wp-cli/cache
chown -R www-data:www-data /var/www/.wp-cli

if [ ! -f /var/www/html/wp-config.php ]; then
    sudo -u www-data wp core download --path=/var/www/html

    sudo -u www-data wp core config \
        --dbname=${MYSQL_DATABASE} \
        --dbuser=${MYSQL_USER} \
        --dbpass=${MYSQL_PASSWORD} \
        --dbhost=mariadb:3306 \
        --path='/var/www/html'

    sudo -u www-data wp core install \
        --url=$DOMAIN_NAME \
        --title="Mon site WordPress" \
        --admin_user=$MYSQL_USER \
        --admin_password="$MYSQL_ROOT_PASSWORD" \
        --admin_email="user@mail.com" \
        --path="/var/www/html"

    echo "define('WP_MAIL_SMTP', false);" | sudo tee -a /var/www/html/wp-config.php
fi

if [ ! -d "/run/php" ]; then
    mkdir -p /run/php
    chown www-data:www-data /run/php
fi

php-fpm7.4 -F
