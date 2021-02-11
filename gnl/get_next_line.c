#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <bsd/string.h>

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
    char *buf;
    static char *store[255];
    int i;
    int j;

    if (BUFFER_SIZE < 1)
        return (-1);
    if (store[fd] == NULL)
        store[fd] = ft_strdup("");
    if (!(*line = ft_strdup(store[fd])))
        return (-1);
    if (ft_strchr(store[fd], '\n') == NULL)
    {
        if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
            return (-1);
        j = 1;
        while (j > 0)
        {
            j = read(fd, buf, BUFFER_SIZE);
            buf[j] = '\0';
            if (ft_strchr(buf, '\n') != NULL)
            {
                i = 0;
                while (buf[i] != '\n')
                    i++;
                ft_strlcat(store[fd], buf, ft_strlen(store[fd]) + i + 1);
                if (!(*line = ft_strdup(store[fd])))
                    return (-1);
                ft_strlcpy(store[fd], &buf[i + 1], ft_strlen(&buf[i + 1]) + 1);
                return (1);
            }
            else
            {
                ft_strlcat(store[fd], buf, ft_strlen(store[fd]) + ft_strlen(buf) + 1);
            }
        }
        if (!(*line = ft_strdup(store[fd])))
            return (-1);
        free(buf);
    }
    else
    {
        i = 0;
        while (store[fd][i] != '\n')
            i++;
        if (!(*line = (char *)malloc(sizeof(char *) * (i + 1))))
            return (-1);
        ft_strlcpy(*line, store[fd], i + 1);
        ft_strlcpy(store[fd], &store[fd][i + 1], ft_strlen(&store[fd][i + 1]) + 1);
        return (1);    
    }
    return (0);
}

int main()
{
    int fd1;
    int fd2;
    char *line = NULL;
    int i;
    int j;

    fd1 = open("sample.txt", O_RDONLY);
    fd2 = open("sample2.txt", O_RDONLY);
    printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
    do 
    {
        i = get_next_line(fd1, &line);
        printf("~~~fd: %d line: %s return: %d~~~\n", fd1, line, i);
        free(line);
        j = get_next_line(fd2, &line);
        printf("~~~fd: %d line: %s return: %d~~~\n", fd2, line, j);
        // free(line);
    } while (i > 0 || j > 0);
    free(line);
    return 0;
}