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
    
# Setup nginx
COPY /srcs/nginx.conf /etc/nginx/sites-available/nginx.conf
RUN ln -s /etc/nginx/sites-available/nginx.conf /etc/nginx/sites-enabled/nginx.conf
RUN rm -rf /etc/nginx/sites-enabled/default
# Setup phpmyadmin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-english.tar.gz && \
    tar -xzvf phpMyAdmin-5.0.2-english.tar.gz && \
    mv phpMyAdmin-5.0.2-english/ /var/www/html/phpmyadmin && \
    rm -rf phpMyAdmin-5.0.2-english.tar.gz
COPY srcs/config.inc.php /var/www/html/phpmyadmin
RUN chown -R www-data:www-data /var/www/html/*

COPY /srcs/container_init.sh /container_init.sh
RUN chmod 744 /container_init.sh
CMD /bin/bash container_init.sh