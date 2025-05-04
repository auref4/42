FROM nginx:stable-bullseye

COPY ./conf/nginx.conf /etc/nginx/nginx.conf
COPY ./conf/nginx.crt /etc/ssl/certs/nginx.crt
COPY ./conf/nginx.key /etc/ssl/private/nginx.key

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
