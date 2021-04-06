FROM debian:buster
RUN apt-get update && apt-get install -y \
    nginx \
    mariadb-server \
    php \
    php-fpm
CMD nginx -g 'daemon off;'