/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:06:32 by hkubo             #+#    #+#             */
/*   Updated: 2021/02/23 18:22:24 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <bsd/string.h>

// int		get_new_line(int fd, char **store, char **line)
// {
// 	int		i;
// 	// char tmp[200];

// 	i = 0;
// 	while (store[fd][i] != '\n')
// 		i++;
// 	printf("i: %d\n", i);
// 	if (!(*line = (char *)malloc(sizeof(char) * (i + 1))))
// 	{
// 		// printf("ng\n");
// 		return (-1);
// 	}
// 	// printf("line_len: %ld store_len: %ld\n", ft_strlen(*line), ft_strlen(store[fd]));
// 	ft_strlcpy(*line, store[fd], i + 1);
// 	printf("line_len: %ld store_len: %ld\n", ft_strlen(*line), ft_strlen(store[fd]));
// 	// ft_strlcpy(tmp, store[fd], i + 1);
// 	// if (!(*line = ft_strdup(tmp)))
// 		// return (-1);
// 	// printf("line_len: %ld\n", ft_strlen(*line));
// 	ft_strlcpy(store[fd], &store[fd][i + 1], ft_strlen(&store[fd][i + 1]) + 1);
// 	return (1);
// }

char	*get_new_line(char *store, char **line)
{
	int		i;
	char 	*tmp = NULL;
	int		size;
	// char tmp[200];
	
	// printf("store_next: %s\n", store);

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

// int		save_new_line(int fd, char **store, char **line, char *buf)
// {
// 	int		i;
// 	int		j;
// 	int		size;
// 	char	*tmp;

// 	i = 0;
// 	while (buf[i] != '\n')
// 		i++;
// 	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(store[fd]) + i + 1))))
// 		return (-1);
// 	ft_strlcpy(tmp, store[fd], ft_strlen(store[fd]) + 1);
// 	size = ft_strlen(tmp);
// 	j = 0;
// 	while (buf[j] != '\0' && (size + j + 1) < (int)ft_strlen(store[fd]) + i + 1)
// 	{
// 		tmp[size + j] = buf[j];
// 		j++;
// 	}
// 	tmp[size + j] = '\0';
// 	free(store[fd]);
// 	store[fd] = tmp;
// 	if (!(*line = ft_strdup(store[fd])))
// 		return (-1);
// 	ft_strlcpy(store[fd], &buf[i + 1], ft_strlen(&buf[i + 1]) + 1);
// 	free(buf);
// 	// printf("store: %s\n", store[fd]);
// 	return (1);
// }

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
	printf("char: %d\n", char_size);
	if (!(tmp = (char *)malloc(sizeof(char) * (char_size))))
		return (NULL);
	if (ft_strlen(store) > 0)
		ft_strlcpy(tmp, store, char_size);
		// ft_strlcpy(tmp, store, ft_strlen(store) + 1);
	size = ft_strlen(store);
	// printf("size: %d\n", size);
	j = 0;
	while (buf[j] != '\0' && (size + j + 1) < (int)ft_strlen(store) + i + 1)
	{
		tmp[size + j] = buf[j];
		j++;
	}
	tmp[size + j] = '\0';
	free(store);
	// store = strdup(tmp);
	// free(tmp);
	// store = tmp;
	if (!(*line = ft_strdup(tmp)))
		return (NULL);
	if (!(tmp2 = (char *)malloc(sizeof(char) * (ft_strlen(&buf[i + 1]) + 1))))
		return (NULL);
	// ft_strlcpy(store, &buf[i + 1], ft_strlen(&buf[i + 1]) + 1);
	ft_strlcpy(tmp2, &buf[i + 1], ft_strlen(&buf[i + 1]) + 1);
	free(buf);
	free(tmp);
	// printf("store: %s\n", store[fd]);
	// return (store);
	return (tmp2);
}

int		get_make_line(int fd, char **store, char **line)
{
	char	*buf;
	int		i;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		// printf("buf: %s\n", buf);
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
			if (!(store[fd] = ft_strjoin(store[fd], buf)))
				return (-1);
		}
	}
	// if (i == 0)
	// {
	// 	// free(store[fd]);
	// 	free(buf);
	// 	return (0);
	// }
	// printf("store: %s\n", store[fd]);
	if (!(*line = ft_strdup(store[fd])))
		return (-1);
	free(buf);
	free(store[fd]);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			j;
	static char *store[255];

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
		// return (get_new_line(fd, store, line));
		store[fd] = get_new_line(store[fd], line);
		if (store[fd] == NULL)
			return (-1);
		return (1);
	}
	// free(store[fd]);
	return (0);
}
