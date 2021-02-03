#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <bsd/string.h>

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
    char *buf;
    static char store[2000000000];
    int i;

    // if (store == NULL)
    //     strcpy(store, "dd\nd");
    strcpy(store, "dd\nd");
    printf("init_store: %s\n", store);
    if (strchr(store, '\n') == NULL)
    {
        if (!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE)))
            return (-1);
        // i = 0;
        while (read(fd, buf, BUFFER_SIZE) > 0)
        {
            if (strchr(buf, '\n') != NULL)
            {
                // while (buf[i] != '\n')
                //     i++;
                // if (i == 0 && strcmp(buf, "") != 0)
                // {
                //     // if (!(*line = strdup(store)))
                //     //     return (-1);
                //     // printf("line: %s\n", *line);
                //     // store = 
                //     return (1);
                // }
                // if (!(*line = strdup(buf)))
                //         return (-1);
                // printf("ok");
                // printf("count: %d\n", i);
            }
            else
            {
                strcat(store, buf);
                
                // printf("buf: %s\n", buf);
                printf("store: %s\n", store);
            }
            if (!(*line = strdup(buf)))
                return (-1);
        }
    }
    else
    {
        i = 0;
        while (store[i] != '\n')
            i++;
        if (!(*line = (char *)malloc(sizeof(char *) * (i + 1))))
            return (-1);
        strlcpy(*line, store, i + 1);
        strcpy(store, &store[i + 1]);
        printf("store: %s\n", store);
        printf("with_line: %d\n", i);
    }
    // 前回は改行前をlineに入れて、その後をstoreに入れる処理を書いた
    // i = read(fd, buf, BUFFER_SIZE);
    // if (!(*line = strdup(buf)))
    //     return (-1);
    // printf("line: %s\n", *line);
    // printf("%d\n", i);
    // printf("%s\n", buf);

    return 0;
}

int main()
{
    int fd;
    char *line = NULL;

    fd = open("sample.txt", O_RDONLY);
    get_next_line(fd, &line);
    printf("line: %s\n", line);
    free(line);
    return 0;
}