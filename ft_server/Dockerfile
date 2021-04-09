FROM debian:buster
RUN apt-get update && apt-get install -y \
    nginx \
    mariadb-server \
    php \
    php-fpm \
    wget
    
COPY /srcs/container_init.sh /container_init.sh
RUN chmod 744 /container_init.sh
CMD /bin/bash container_init.sh