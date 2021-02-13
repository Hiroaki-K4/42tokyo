/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:06:32 by hkubo             #+#    #+#             */
/*   Updated: 2021/02/13 15:39:34 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    char *tmp;
    int i;
    int j;

    if (BUFFER_SIZE < 1)
        return (-1);
    if (store[fd] == NULL)
    {
        if (!(store[fd] = ft_strdup("")))
            return (-1);
    }
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
            // printf("j: %d\n", j);
            if (j == -1)
                return (-1);
            if (ft_strchr(buf, '\n') != NULL)
            {
                i = 0;
                while (buf[i] != '\n')
                    i++;
                // if (!(store[fd] = ft_strjoin(store[fd], buf)))
                    // return (-1);
                if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(store[fd]) + i + 1))))
                    return (-1);
                ft_strlcpy(tmp, store[fd], ft_strlen(store[fd]) + 1);
                ft_strlcat(tmp, buf, ft_strlen(store[fd]) + i + 1);
                free(store[fd]);
                store[fd] = tmp;
                if (!(*line = ft_strdup(store[fd])))
                    return (-1);
                ft_strlcpy(store[fd], &buf[i + 1], ft_strlen(&buf[i + 1]) + 1);
                return (1);
            }
            else
            {
                // printf("buf_len: %ld, buf: %s\n", ft_strlen(buf), buf);
                // ft_strlcat(store[fd], buf, ft_strlen(store[fd]) + ft_strlen(buf) + 1);
                if (!(store[fd] = ft_strjoin(store[fd], buf)))
                    return (-1);
                // strlcat(store[fd], buf, ft_strlen(store[fd]) + ft_strlen(buf) + 1);
            }
            // free(buf);
            // printf("store_len: %ld\n", ft_strlen(store[fd]));
            // printf("store: %s\n", store[fd]);
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

int main(int argc, char *argv[])
{
    int fd1;
    int fd2;
    char *line = NULL;
    int i;
    int j;

    if (argc == 1)
    {
        i = get_next_line(2, &line);
        printf("~~~fd: %d line: %s return: %d~~~\n", 0, line, i);
        free(line);
    }
    if (argc == 2)
    {
        fd1 = open(argv[1], O_RDONLY);
        printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
        do 
        {
            i = get_next_line(fd1, &line);
            printf("~~~fd: %d line: %s return: %d~~~\n", fd1, line, i);
            free(line);
            // free(line);
        } while (i > 0);
        // free(line);
    }
    if (argc == 3)
    {
        fd1 = open(argv[1], O_RDONLY);
        fd2 = open(argv[2], O_RDONLY);
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
    }
    return (0);
}