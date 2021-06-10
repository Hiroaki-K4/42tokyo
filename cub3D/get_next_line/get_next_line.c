/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:06:32 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/10 22:42:03 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_new_line(char *store, char **line)
{
	int		i;
	int		size;
	char	*tmp;

	tmp = NULL;
	i = 0;
	size = 0;
	while (store[i] != '\n' && store[i] != '\0')
		i++;
	*line = (char *)malloc(sizeof(char) * (i + 1));
	if (!*line)
		return (NULL);
	ft_strlcpy(*line, store, i + 1);
	size = (int)ft_strlen(&store[i + 1]) + 1;
	tmp = (char *)malloc(sizeof(char) * size);
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, &store[i + 1], ft_strlen(&store[i + 1]) + 1);
	free(store);
	return (tmp);
}

void	save_new_line_support(char *store, char *tmp, char *buf, int i)
{
	int	j;

	j = -1;
	while (buf[++j] && (ft_strlen(store) + j + 1) < (ft_strlen(store) + i + 1))
		tmp[ft_strlen(store) + j] = buf[j];
	tmp[ft_strlen(store) + j] = '\0';
	free(store);
}

char	*save_new_line(char *store, char **line, char *buf)
{
	int		i;
	char	*tmp;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(store) + i + 1));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, store, ft_strlen(store) + 1);
	save_new_line_support(store, tmp, buf, i);
	*line = ft_strdup(tmp);
	if (!*line)
		return (NULL);
	free(tmp);
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(&buf[i + 1]) + 1));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, &buf[i + 1], ft_strlen(&buf[i + 1]) + 1);
	free(buf);
	return (tmp);
}

int	get_make_line(int fd, char **store, char **line, int i)
{
	char	*buf;
	char	*tmp;

	buf = (char *)malloc(sizeof(char) * 17);
	while (i > 0)
	{
		i = read(fd, buf, 16);
		if (i == -1)
			return (-1);
		buf[i] = '\0';
		if (ft_strchr(buf, '\n') != NULL)
		{
			store[fd] = save_new_line(store[fd], line, buf);
			if (!store[fd])
				return (-1);
			return (1);
		}
		tmp = ft_strjoin(store[fd], buf);
		free(store[fd]);
		store[fd] = tmp;
	}
	*line = ft_strdup(store[fd]);
	free(buf);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int			i;
	static char	*store[256];

	*line = NULL;
	if (store[fd] == NULL)
	{
		store[fd] = ft_strdup("");
		if (!store[fd])
			return (-1);
	}
	if (ft_strchr(store[fd], '\n') == NULL)
	{
		i = get_make_line(fd, store, line, 1);
		if (i == 0)
			free(store[fd]);
		return (i);
	}
	else
	{
		store[fd] = get_new_line(store[fd], line);
		if (!store[fd])
			return (-1);
		return (1);
	}
	return (0);
}
