/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:06:32 by hkubo             #+#    #+#             */
/*   Updated: 2021/02/14 10:21:12 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char *buf;
	static char *store[255];
	char *tmp;
	int i;
	int j;

	if (BUFFER_SIZE < 1)
		return (-1);
	if (store[fd] == NULL)
		if (!(store[fd] = ft_strdup("")))
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
			if (j == -1)
				return (-1);
			if (ft_strchr(buf, '\n') != NULL)
			{
				i = 0;
				while (buf[i] != '\n')
					i++;
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
				if (!(store[fd] = ft_strjoin(store[fd], buf)))
					return (-1);
			}
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
