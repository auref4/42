FROM debian:bullseye

RUN apt-get update && apt-get install -y nginx

RUN mkdir -p /etc/nginx/ssl/private
RUN mkdir -p /etc/nginx/ssl/certs

COPY ./conf/nginx.conf /etc/nginx/nginx.conf

RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html

RUN apt-get install -y openssl
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/nginx.crt -keyout /etc/nginx/ssl/nginx.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=${DOMAIN_NAME}/UID=${LOGIN}"

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
