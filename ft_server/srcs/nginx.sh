# !/bin/sh

if [ "$AUTO_INDEX" = "on" ];
then cp /etc/nginx/sites-available/nginx.conf /etc/nginx/sites-available/default;
else cp /etc/nginx/sites-available/nginx_index_off.conf /etc/nginx/sites-available/default;
fi