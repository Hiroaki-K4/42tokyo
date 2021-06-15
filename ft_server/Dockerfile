# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/15 21:15:45 by hkubo             #+#    #+#              #
#    Updated: 2021/04/17 22:20:08 by hkubo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster
RUN apt-get update && apt-get install -y \
    nginx \
    mariadb-server \
    php \
    php-fpm \
    php-mysql \
    php-mbstring \
    wget
    
ENV AUTO_INDEX="on"

# Setup nginx
COPY srcs/nginx.conf /etc/nginx/sites-available/nginx.conf
COPY srcs/nginx_index_off.conf /etc/nginx/sites-available/nginx_index_off.conf
COPY srcs/*.sh /
RUN rm /var/www/html/index.nginx-debian.html && chmod 744 nginx.sh

# Setup phpmyadmin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-english.tar.gz && \
    tar -xzvf phpMyAdmin-5.0.2-english.tar.gz && \
    mv phpMyAdmin-5.0.2-english/ /var/www/html/phpmyadmin && \
    rm -rf phpMyAdmin-5.0.2-english.tar.gz
COPY srcs/config.inc.php /var/www/html/phpmyadmin

# Setup wordpress
RUN wget https://wordpress.org/latest.tar.gz && \
    tar -xvzf latest.tar.gz && rm -rf latest.tar.gz && \
    mv wordpress /var/www/html
COPY srcs/wp-config.php /var/www/html/wordpress

# Setup SSL
RUN wget https://github.com/FiloSottile/mkcert/releases/download/v1.4.3/mkcert-v1.4.3-linux-amd64 && \
    mv mkcert-v1.4.3-linux-amd64 mkcert && chmod +x mkcert && \
    ./mkcert -install && ./mkcert localhost && mkdir /etc/nginx/ssl && \
    mv localhost-key.pem localhost.pem /etc/nginx/ssl

RUN chown -R www-data:www-data /var/www/html/*
EXPOSE 80 443
RUN chmod 744 container_init.sh
CMD /bin/bash container_init.sh