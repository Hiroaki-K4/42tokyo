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
    strcpy(store, "");
    // printf("init_store: %s\n", store);
    if (strchr(store, '\n') == NULL)
    {
        if (!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE)))
            return (-1);
        i = 0;
        while (read(fd, buf, BUFFER_SIZE) > 0)
        {
            if (strchr(buf, '\n') != NULL)
            {
                while (buf[i] != '\n')
                    i++;
                // printf("i: %d\n", i);
                // 2回目のstrcatした後の値がおかしい
                printf("before_store: %s\n", buf);
                strlcat(store, buf, strlen(store) + i + 1);
                printf("strcat: %s\n", store);
                if (!(*line = strdup(store)))
                    return (-1);
                strcpy(store, &buf[i + 1]);
                printf("store_1: %s\n", store);
                return (1);
            }
            else
            {
                strcat(store, buf);
                
                printf("store_3: %s\n", store);
            }
            printf("buf: %s\n", buf);
            if (!(*line = strdup(store)))
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
        printf("store_2: %s\n", store);
        return (1);    
    }
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
    int i;

    fd = open("sample.txt", O_RDONLY);
    do 
    {
        i = get_next_line(fd, &line);
        printf("line: %s return: %d\n", line, i);
        free(line);
    } while (i > 0);
    free(line);
    // TO DO 最後の行の出力がおかしいのを修正
    return 0;
}