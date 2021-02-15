/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:06:32 by hkubo             #+#    #+#             */
/*   Updated: 2021/02/15 22:07:08 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_new_line(int fd, char **store, char **line)
{
	int		i;

	i = 0;
	while (store[fd][i] != '\n')
		i++;
	if (!(*line = (char *)malloc(sizeof(char *) * (i + 1))))
		return (-1);
	ft_strlcpy(*line, store[fd], i + 1);
	ft_strlcpy(store[fd], &store[fd][i + 1], ft_strlen(&store[fd][i + 1]) + 1);
	return (1);
}

int		save_new_line(int fd, char **store, char **line, char *buf)
{
	int		i;
	int		j;
	int		size;
	char	*tmp;

	i = 0;
	while (buf[i] != '\n')
		i++;
	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(store[fd]) + i + 1))))
		return (-1);
	ft_strlcpy(tmp, store[fd], ft_strlen(store[fd]) + 1);
	size = ft_strlen(tmp);
	j = 0;
	while (buf[j] != '\0' && (size + j + 1) < (int)ft_strlen(store[fd]) + i + 1)
	{
		tmp[size + j] = buf[j];
		j++;
	}
	tmp[size + j] = '\0';
	free(store[fd]);
	store[fd] = tmp;
	if (!(*line = ft_strdup(store[fd])))
		return (-1);
	ft_strlcpy(store[fd], &buf[i + 1], ft_strlen(&buf[i + 1]) + 1);
	return (1);
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
		// printf("i: %d\n", i);
		buf[i] = '\0';
		if (i == -1)
			return (-1);
		if (ft_strchr(buf, '\n') != NULL)
			return (save_new_line(fd, store, line, buf));
		else
		{
			if (!(store[fd] = ft_strjoin(store[fd], buf)))
				return (-1);
		}
	}
	if (!(*line = ft_strdup(store[fd])))
		return (-1);
	free(buf);
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
		// return (0);
	}
	else
		return (get_new_line(fd, store, line));
	return (0);
}
