/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:06:32 by hkubo             #+#    #+#             */
/*   Updated: 2021/04/05 22:34:38 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_from_store(char *store, char **line)
{
	int		i;
	int		size;
	char	*tmp;

	tmp = NULL;
	i = 0;
	size = 0;
	while (store[i] != '\n' && store[i] != '\0')
		i++;
	if (!(*line = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_strlcpy(*line, store, i + 1);
	size = (int)ft_strlen(&store[i + 1]) + 1;
	if (!(tmp = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_strlcpy(tmp, &store[i + 1], size);
	free(store);
	return (tmp);
}

char	*save_new_line(char *store, char **line, char *buf)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (buf[i] != '\n')
		i++;
	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(store) + i + 1))))
		return (NULL);
	ft_strlcpy(tmp, store, ft_strlen(store) + 1);
	j = -1;
	while (buf[++j] && j < i)
		tmp[ft_strlen(store) + j] = buf[j];
	tmp[ft_strlen(store) + j] = '\0';
	free(store);
	if (!(*line = ft_strdup(tmp)))
		return (NULL);
	free(tmp);
	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(&buf[i + 1]) + 1))))
		return (NULL);
	ft_strlcpy(tmp, &buf[i + 1], ft_strlen(&buf[i + 1]) + 1);
	free(buf);
	return (tmp);
}

int		read_line(int fd, char **store, char **line, int i)
{
	char	*buf;
	char	*tmp;
	int		buffer_size;

	buffer_size = 128;
	if (!(buf = (char *)malloc(sizeof(char) * ((size_t)buffer_size + 1))))
		return (-1);
	while (i > 0)
	{
		if ((i = read(fd, buf, buffer_size)) == -1)
			return (-1);
		buf[i] = '\0';
		if (ft_strchr(buf, '\n') != NULL)
		{
			if (!(store[fd] = save_new_line(store[fd], line, buf)))
				return (-1);
			return (1);
		}
		if (!(tmp = ft_strjoin(store[fd], buf)))
			return (-1);
		free(store[fd]);
		store[fd] = tmp;
	}
	if (!(*line = ft_strdup(store[fd])))
		return (-1);
	free(buf);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			i;
	static char *store[256];

<<<<<<< HEAD
// 	*line = NULL;
// 	if (fd < 0 || fd > 255)
// 		return (-1);
// 	if (store[fd] == NULL)
// 		if (!(store[fd] = ft_strdup("")))
// 			return (-1);
// 	if (ft_strchr(store[fd], '\n') == NULL)
// 	{
// 		if ((i = read_line(fd, store, line, 1)) == 0)
// 		{
// 			free(store[fd]);
// 			store[fd] = NULL;
// 		}
// 		return (i);
// 	}
// 	else
// 	{
// 		if (!(store[fd] = get_from_store(store[fd], line)))
// 			return (-1);
// 		return (1);
// 	}
// 	return (0);
// }

int read_line(int fd, char **store, char **line, int i)
{
    int buffer_size;
    char *buf;
    char *tmp;

    if (!(buf = (char *)malloc(sizeof(char) * (buffer_size + 1))))
        return (-1);
    buffer_size = 128;
    while ((i > 0)
    {
        if ((i = read(fd, buf, buffer_size)) == -1)
            return (-1);
        buf[i] = '\0';
        if (ft_strchr(buf, '\n') != NULL)
        {
            if (!(store[fd] = save_new_line(char *store, char **line, char *buf)))
                return (-1);
            free(buf);
            return (1);
        }
        if (!(tmp = ft_strjoin(store[fd], buf)))
            return (-1);
        free(store[fd]);
        store[fd] = tmp;
    }
    free(buf);
    return (0);
}

int get_next_line(int fd, char **line)
{
    int         i;
    static char *store[255];

    
    *line = NULL;
    if (fd < 0 || fd > 255)
        return (-1);
    if (store[fd] == NULL)
        store[fd] = ft_strdup("");
    if (ft_strchr(store[fd], '\n') == NULL)
    {
        if ((i = read_line(fd, store, line, 1)) == 0)
        {
            free(store[fd]);
            store[fd] = NULL;
        }
        return (i);
    }
    else
    {
        if (!(store[fd] = get_from_store(store[fd], line)))
            return (-1);
        return (1);
    }
    return (0);
}
=======
	*line = NULL;
	if (fd < 0 || fd > 255)
		return (-1);
	if (store[fd] == NULL)
		if (!(store[fd] = ft_strdup("")))
			return (-1);
	if (ft_strchr(store[fd], '\n') == NULL)
	{
		if ((i = read_line(fd, store, line, 1)) == 0)
		{
			free(store[fd]);
			store[fd] = NULL;
		}
		return (i);
	}
	else
	{
		if (!(store[fd] = get_from_store(store[fd], line)))
			return (-1);
		return (1);
	}
	return (0);
}
>>>>>>> d718915e30a117d313415cc4712d8362f4bb52ea
