# libft
C programming can be very tedious when one doesn’t have access to those highly useful
standard functions. This project gives you the opportunity to re-write those functions,
understand them, and learn to use them. This library will help you for all your future C
projects.
Through this project, we also give you the opportunity to expand the list of functions
with your own. Take the time to expand your libft throughout the year.

<br>

# Referenced links
- [About Web server](https://developer.mozilla.org/en-US/docs/Learn/Common_questions/What_is_a_web_server)
- [nginx Beginners Guide](http://nginx.org/en/docs/beginners_guide.html)
- [Setup nginx, mariaDB and php](https://www.digitalocean.com/community/tutorials/how-to-install-linux-nginx-mariadb-php-lemp-stack-on-debian-10)
- [Autoindex](https://qiita.com/onokatio/items/4669b37644fe07d3aa80)

<br>

# How to run
**Build docker image**
```
docker build -t ft_server.
```

**Run docker container**
```
docker run --name ft_server -d -p 443:443 -p 8080:80 ft_server
```

**Turn off autoindex**
```
docker run --env AUTO_INDEX="off" --name ft_server -d -p 443:443 -p 8080:80 ft_server
```

**Enter container**
```
docker exec -it container_id /bin/bash
```

**Access home URL**
```
http://localhost:8080
```
![Screenshot from 2021-04-15 18-11-06](https://user-images.githubusercontent.com/51109408/114844911-388a7800-9e16-11eb-8394-46ed29c9fae0.png)


**Access phpmyadmin URL**
```
http://localhost:8080/phpmyadmin
```
![Screenshot from 2021-04-15 18-11-28](https://user-images.githubusercontent.com/51109408/114844990-4fc96580-9e16-11eb-9cb0-afbe1e716361.png)

**Access wordpress URL**
```
http://localhost:8080/wordpress
```
![Screenshot from 2021-04-15 18-11-49](https://user-images.githubusercontent.com/51109408/114845027-56f07380-9e16-11eb-95d8-9deb99276b5d.png)

**Use the SSL protcol**
```
https://localhost:8080
```
