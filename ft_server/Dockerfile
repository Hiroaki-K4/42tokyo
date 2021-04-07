FROM debian:buster
RUN apt-get update && apt-get install -y \
    nginx \
    mariadb-server \
    php \
    php-fpm
    
COPY ./srcs/docker_init.sh ./root
CMD /bin/bash docker_init.sh