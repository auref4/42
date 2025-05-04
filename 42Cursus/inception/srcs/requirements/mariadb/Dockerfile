FROM debian:bullseye

RUN apt-get update && apt-get install -y mariadb-server
RUN chown -R mysql:mysql /var/lib/mysql

COPY ./conf/mariadb.cnf /etc/mysql/conf.d/
COPY ./tools/entrypoint.sh /usr/local/bin/entrypoint.sh

RUN chmod +x /usr/local/bin/entrypoint.sh

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]

EXPOSE 3306

