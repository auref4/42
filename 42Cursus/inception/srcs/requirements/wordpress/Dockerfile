FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    sudo \
    wget \
    php7.4-fpm \
    php7.4-mysql \
    mariadb-client \
    curl \
    unzip \
    bash

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar -P /usr/local/bin/
RUN chmod +x /usr/local/bin/wp-cli.phar
RUN mv /usr/local/bin/wp-cli.phar /usr/local/bin/wp

COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf
COPY ./tools/script.sh /usr/local/bin/script.sh

RUN chmod +x /usr/local/bin/script.sh

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/script.sh"]
