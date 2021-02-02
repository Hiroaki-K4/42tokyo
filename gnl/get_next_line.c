#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
    char *buf;
    static char *store;
    int i;

    if (store == NULL)
        store = "d";
    if (strchr(store, '\n') == NULL)
    {
        if (!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE)))
            return (-1);
        i = 0;
        while (read(fd, buf, BUFFER_SIZE) > 0)
        {
            printf("buf: %s\n", buf);
            if (strchr(buf, '\n') != NULL)
            {
                while (buf[i] != '\n')
                    i++;
                if (i == 0 && strcmp(buf, "") != 0)
                {
                    if (!(*line = strdup(store)))
                        return (-1);
                    printf("line: %s\n", *line);
                    // store = 
                    return (1);
                }
                printf("count: %d\n", i);
            }
            else
            {
                // TO DO 改行が見つからないときに既存のstoreにつなげる処理を書く
                strcalt(store, buf);
            }

            // if (!(*line = strdup(buf)))
            //     return (-1);
        }
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

    fd = open("sample.txt", O_RDONLY);
    get_next_line(fd, &line);
    printf("line: %s\n", line);
    return 0;
}