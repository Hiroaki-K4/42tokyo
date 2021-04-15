## ft_server
This topic is intended to introduce you to system administration. It will make you aware of the importance of using scripts to automate your tasks.
For that, you will discover the "docker" technology and use it to install a complete web server. This server will run multiples services: Wordpress, phpMyAdmin, 
and a SQL database.

<br>

## Referenced links
**Nginx**
- [About Web server](https://developer.mozilla.org/en-US/docs/Learn/Common_questions/What_is_a_web_server)
- [Beginners Guide](http://nginx.org/en/docs/beginners_guide.html)
- [Setup nginx, mariaDB and php](https://www.digitalocean.com/community/tutorials/how-to-install-linux-nginx-mariadb-php-lemp-stack-on-debian-10)

<br>

## How to run
**Build docker image**
```
docker build -t ft_server.
```
**Run docker container**
```
docker run --name ft_server -d -p 443:443 -p 8080:80 ft_server
```
