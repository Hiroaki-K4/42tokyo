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
    // *store[255]で複数ファイル対応にする
    static char *store[255];
    int i;
    int j;

    if (BUFFER_SIZE < 1)
        return (-1);
    // if (store == NULL)
    //     strcpy(store, "dd\nd");
    if (store[fd] == NULL)
        store[fd] = strdup("");
        // printf("fd: %d\n", fd);
        // strcpy(store[fd], "");
    if (!(*line = strdup(store[fd])))
        return (-1);
    // printf("init_store: %s\n", store);
    if (strchr(store[fd], '\n') == NULL)
    {
        if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
            return (-1);
        j = 1;
        while (j > 0)
        {
            j = read(fd, buf, BUFFER_SIZE);
            // printf("j: %d\n", j);
            buf[j] = '\0';
            // printf("buf: %s\n", buf);
            // printf("buf_len: %ld\n", strlen(buf));
            if (strchr(buf, '\n') != NULL)
            {
                i = 0;
                while (buf[i] != '\n')
                    i++;
                // printf("i: %d\n", i);
                // printf("before_store: %s\n", buf);
                strlcat(store[fd], buf, strlen(store[fd]) + i + 1);
                // printf("strcat: %s\n", store);
                if (!(*line = strdup(store[fd])))
                    return (-1);
                strcpy(store[fd], &buf[i + 1]);
                // printf("store_1: %s\n", store);
                return (1);
            }
            else
            {
                strcat(store[fd], buf);
                // strcpy(buf, "");
                // printf("store_3: %s\n", store);
            }
            // printf("buf: %s\n", buf);
            // printf("store: %s\n", store);
            // 下の2行はほんとはいらないはず
            // if (!(*line = strdup(store)))
            //     return (-1);
        }
        if (!(*line = strdup(store[fd])))
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
        strlcpy(*line, store[fd], i + 1);
        strcpy(store[fd], &store[fd][i + 1]);
        // printf("store_2: %s\n", store);
        return (1);    
    }
    return 0;
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