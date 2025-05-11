#!/bin/bash

# Initialisation de la base de données si elle n'existe pas déjà
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initialisation de la base de données..."
    mysqld --initialize-insecure --user=mysql
    echo "Base de données initialisée"
fi

# Démarrage de MariaDB en arrière-plan
mysqld_safe --datadir='/var/lib/mysql' --user=mysql &

# Attente que MariaDB soit complètement démarré
until mysqladmin ping --silent; do
    echo "En attente de MariaDB..."
    sleep 2
done

# Création de la base de données si elle n'existe pas déjà
echo "Création de la base de données ${MYSQL_DATABASE}..."
mysql -u root -e "CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;"
mysql -u root -e "CREATE USER IF NOT EXISTS \`${MYSQL_USER}\`@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';"
mysql -u root -e "GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO \`${MYSQL_USER}\`@'%';"
mysql -u root -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';"

# Fermer MariaDB après l'initialisation
mysqladmin -u root -p"${MYSQL_ROOT_PASSWORD}" shutdown

# Redémarrage de MariaDB en mode normal
exec mysqld_safe --datadir='/var/lib/mysql' --user=mysql
