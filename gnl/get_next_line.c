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
    if (store == NULL)
        strcpy(store, "");
    printf("init_store: %s\n", store);
    if (strchr(store, '\n') == NULL)
    {
        if (!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE)))
            return (-1);
        i = 0;
        // もう読み込まれることがないとき(eofまで到達している)の処理を書く
        while (read(fd, buf, BUFFER_SIZE) > 0)
        {
            if (strchr(buf, '\0') == NULL)
                printf("ok");
            buf[BUFFER_SIZE] = '\0';
            // printf("buf_len: %ld\n", strlen(buf));
            if (strchr(buf, '\n') != NULL)
            {
                while (buf[i] != '\n')
                    i++;
                // printf("i: %d\n", i);
                // printf("before_store: %s\n", buf);
                strlcat(store, buf, strlen(store) + i + 1);
                // printf("strcat: %s\n", store);
                if (!(*line = strdup(store)))
                    return (-1);
                strcpy(store, &buf[i + 1]);
                // printf("store_1: %s\n", store);
                return (1);
            }
            else
            {
                strcat(store, buf);
                
                // printf("store_3: %s\n", store);
            }
            // printf("buf: %s\n", buf);
            printf("store: %s\n", store);
            // 下の2行はほんとはいらないはず
            if (!(*line = strdup(store)))
                return (-1);
        }
        // buffer_sizeがすごく大きいときの処理を書く
        // if (buf[0] != '\0')
        // {
        //     while (strlen(buf) > 0)
        //     {
        //         i = 0;
        //         while (buf[i] != '\n' && buf[i] != '\0')
        //             i++;
        //         // printf("buf: %s\n", buf);
        //         if (buf[i] == '\n')
        //         {
        //             if (!(*line = (char *)malloc(sizeof(char *) * (i + 1))))
        //                 return (-1);
        //             strlcpy(*line, buf, i + 1);
        //             strcpy(store, &buf[i + 1]);
        //             // printf("store_2: %s\n", store);
        //             return (1);    
        //         }
        //         if (buf[i] == '\0')
        //         {
        //             if (!(*line = (char *)malloc(sizeof(char *) * i)))
        //                 return (-1);
        //             strcat(store, buf);
        //             strcpy(*line, store);
        //             return (0);
        //         }
        //     }
            
        //     return (0);
        // }
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
        // printf("store_2: %s\n", store);
        return (1);    
    }
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
        printf("~~~line: %s return: %d~~~\n", line, i);
        // free(line);
    } while (i > 0);
    // free(line);
    return 0;
}