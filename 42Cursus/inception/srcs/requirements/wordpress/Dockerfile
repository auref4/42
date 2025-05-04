FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    wget \
    php-fpm \
    php-mysql \
    mariadb-client


RUN wget https://fr.wordpress.org/wordpress-6.0-fr_FR.tar.gz -P /var/www
RUN cd /var/www && tar -xzf wordpress-6.0-fr_FR.tar.gz && rm wordpress-6.0-fr_FR.tar.gz
RUN chown -R root:root /var/www/wordpress

COPY ./conf/php.ini /etc/php/7.4/fpm/php.ini
COPY ./conf/wp-config.php /var/www/html/wp-config.php

RUN sed -i "s/database_name_here/${MYSQL_DATABASE}/" /var/www/html/wp-config.php && \
    sed -i "s/username_here/${MYSQL_USER}/" /var/www/html/wp-config.php && \
    sed -i "s/password_here/${MYSQL_PASSWORD}/" /var/www/html/wp-config.php && \
    sed -i "s/localhost/${MYSQL_HOST}/" /var/www/html/wp-config.php

EXPOSE 9000

CMD ["php-fpm7.4", "-F"]
