#!/bin/bash

#init database
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initialisation de MariaDB..."
    mysqld --initialize-insecure --user=mysql
fi

#exec mariadb
exec mysqld_safe --datadir='/var/lib/mysql' --user=mysql
