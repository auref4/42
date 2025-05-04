#!/bin/bash

# Vérifie si le répertoire de base de données existe
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initialisation de MariaDB..."
    mysqld --initialize-insecure --user=mysql  # Initialise la base de données si elle n'existe pas
fi

# Lance MariaDB en mode sécurisé
exec mysqld_safe --datadir='/var/lib/mysql' --user=mysql

