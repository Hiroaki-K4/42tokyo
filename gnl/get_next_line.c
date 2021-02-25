/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:06:32 by hkubo             #+#    #+#             */
/*   Updated: 2021/02/25 14:08:59 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <bsd/string.h>

char	*get_new_line(char *store, char **line)
{
	int		i;
	char 	*tmp = NULL;
	int		size;	

	i = 0;
	size = 0;
	// tmp = ft_strdup("");
	while (store[i] != '\n' && store[i] != '\0')
		i++;
	if (!(*line = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	// printf("store_be: %s\n", store);
	ft_strlcpy(*line, store, i + 1);
	// printf("store_af: %s\n", &store[i + 1]);
	// ft_strlcpy(tmp, store[fd], i + 1);
	// if (!(*line = ft_strdup(tmp)))
		// return (-1);
	size = (int)ft_strlen(&store[i + 1]) + 1;
	// printf("size: %d\n", size);
	// printf("store_af: %s\n", store);
	// if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(&store[i + 1]) + 1))))
	if (!(tmp = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	// printf("store_after: %s\n", store);
	ft_strlcpy(tmp, &store[i + 1], ft_strlen(&store[i + 1]) + 1);
	// printf("tmp: %s\n", tmp);
	free(store);
	return (tmp);
}


char	*save_new_line(char *store, char **line, char *buf)
{
	int		i;
	int		j;
	int		char_size;
	int		size;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (buf[i] != '\n')
		i++;
	// tmp = NULL;
	char_size = (int)ft_strlen(store) + i + 1;
	if (!(tmp = (char *)malloc(sizeof(char) * (char_size))))
		return (NULL);
	if (ft_strlen(store) > 0)
		ft_strlcpy(tmp, store, char_size);
	size = ft_strlen(store);
	j = 0;
	while (buf[j] != '\0' && (size + j + 1) < (int)ft_strlen(store) + i + 1)
	{
		tmp[size + j] = buf[j];
		j++;
	}
	tmp[size + j] = '\0';
	free(store);
	if (!(*line = ft_strdup(tmp)))
		return (NULL);
	if (!(tmp2 = (char *)malloc(sizeof(char) * (ft_strlen(&buf[i + 1]) + 1))))
		return (NULL);
	ft_strlcpy(tmp2, &buf[i + 1], ft_strlen(&buf[i + 1]) + 1);
	free(buf);
	free(tmp);
	return (tmp2);
}

int		get_make_line(int fd, char **store, char **line)
{
	char	*buf;
	int		i;
	char	*tmp;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		buf[i] = '\0';
		if (i == -1)
			return (-1);
		if (ft_strchr(buf, '\n') != NULL)
		{
			store[fd] = save_new_line(store[fd], line, buf);
			if (store[fd] == NULL)
				return (-1);
			return (1);
		}
		else
		{
			if (!(tmp = ft_strjoin(store[fd], buf)))
				return (-1);
			free(store[fd]);
			store[fd] = tmp;
		}
	}
	if (!(*line = ft_strdup(store[fd])))
		return (-1);
	free(buf);
// free(store[fd]);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			j;
	static char *store[255];

	*line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (store[fd] == NULL)
		if (!(store[fd] = ft_strdup("")))
			return (-1);
	if (ft_strchr(store[fd], '\n') == NULL)
	{
		j = get_make_line(fd, store, line);
		if (j == 1)
			return (1);
		if (j == -1)
			return (-1);
	}
	else
	{
		store[fd] = get_new_line(store[fd], line);
		if (store[fd] == NULL)
			return (-1);
		return (1);
	}
	return (0);
}
