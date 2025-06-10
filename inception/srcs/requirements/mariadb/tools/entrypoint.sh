#!/bin/bash

if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initialisation de la base de données..."
    mysqld --initialize-insecure --user=mysql
    echo "Base de données initialisée"
fi

mysqld_safe --datadir='/var/lib/mysql' --user=mysql &

until mysqladmin ping --silent; do
    echo "En attente de MariaDB..."
    sleep 2
done

echo "Création de la base de données ${MYSQL_DATABASE}..."
mysql -u root -e "CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;"
mysql -u root -e "CREATE USER IF NOT EXISTS \`${MYSQL_USER}\`@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';"
mysql -u root -e "GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO \`${MYSQL_USER}\`@'%';"
mysql -u root -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';"

mysqladmin -u root -p"${MYSQL_ROOT_PASSWORD}" shutdown

exec mysqld_safe --datadir='/var/lib/mysql' --user=mysql
