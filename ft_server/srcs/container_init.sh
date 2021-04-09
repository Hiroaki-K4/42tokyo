# !/bin/sh

service php7.3-fpm start
service mysql start
# service nginx start
tail -f /dev/null