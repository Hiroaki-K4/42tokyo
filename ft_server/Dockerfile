FROM debian:buster
RUN apt-get update && apt-get install -y \
    nginx \
    mariadb-server \
    php \
    php-fpm \
    php-mysql \
    wget \
    vim \
    curl
    
COPY /srcs/container_init.sh /container_init.sh
COPY /srcs/nginx.conf /etc/nginx/sites-available/nginx.conf
RUN ln -s /etc/nginx/sites-available/nginx.conf /etc/nginx/sites-enabled/nginx.conf
RUN rm -rf /etc/nginx/sites-enabled/default
RUN chmod 744 /container_init.sh
CMD /bin/bash container_init.sh