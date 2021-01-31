#include <stdio.h>
#include <fcntl.h>


// int get_next_line(int fd, char **line)
// {
//     char buf[100];
//     int i;
//     i = read(fd, buf, 3);
//     printf("%s", buf);
//     return 0;
// }


int main()
{
    int fd;

    fd = open("sample.txt", O_RDONLY);
    printf("%d", fd);
    // get_next_line(fd, NULL);
    return 0;
}