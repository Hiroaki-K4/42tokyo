FROM debian:buster
RUN apt-get update && apt-get install -y \
    nginx \
    mariadb-server \
    php \
    php-fpm
    
COPY /srcs/docker_init.sh /docker_init.sh
RUN chmod 744 /docker_init.sh
CMD /bin/bash docker_init.sh