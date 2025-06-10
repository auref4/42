# Utiliser l'image officielle de Debian comme base
FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    mariadb-server \
    sudo \
    wget \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/lib/mysql
RUN chown -R mysql:mysql /var/lib/mysql

COPY ./conf/my.cnf /etc/mysql/my.cnf
COPY ./tools/entrypoint.sh /usr/local/bin/entrypoint.sh

RUN chmod +x /usr/local/bin/entrypoint.sh

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]

EXPOSE 3306

CMD ["mysqld_safe"]
