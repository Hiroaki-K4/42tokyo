/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:06:32 by hkubo             #+#    #+#             */
/*   Updated: 2021/04/24 18:02:45 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		i;
	
	i = 0;
	while (s[i] != '\0')
		i++;
	if (!(new_str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char const	*ptr_s;
	int					i;

	ptr_s = (unsigned char const *)s;
	i = 0;
	while (ptr_s[i] != '\0')
	{
		if (ptr_s[i] == (unsigned char)c)
			return (char *)(s + i);
		i++;
	}
	if (ptr_s[i] == '\0' && ptr_s[i] == (unsigned char)c)
		return (char *)(s + i);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	new_str_len;
	char	*new_str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	new_str_len = ft_strlen(s1) + ft_strlen(s2);
	if (!(new_str = (char *)malloc(sizeof(char) * (new_str_len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		new_str[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	ans;

	ans = ft_strlen(src);
	if (n == 0)
		return (ans);
	i = 0;
	while (i < n - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ans);
}

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

int		read_line(int fd, char **store, char **line)
{
	int		i;
	char	*buf;
	char	*tmp;
	int		buffer_size;

	buffer_size = 128;
	if (!(buf = (char *)malloc(sizeof(char) * ((size_t)buffer_size + 1))))
		return (-1);
	i = 1;
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

// int get_next_line(int fd, char **line)
// {
//     int         i;
//     static char *store[255];

//     *line = NULL;
//     if (fd < 0 || fd > 255)
//         return (-1);
//     if (store[fd] == NULL)
//         store[fd] = ft_strdup("");
//     if (ft_strchr(store[fd], '\n') == NULL)
//     {
//         if ((i = read_line(fd, store, line)) == 0)
//         {
//             free(store[fd]);
//             store[fd] = NULL;
//         }
//         return (i);
//     }
//     else
//     {
//         if (!(store[fd] = get_from_store(store[fd], line)))
//             return (-1);
//         return (1);
//     }
//     return (0);
// }

int get_next_line(int fd, char **line)
{
	int i;
	static char *store[255];

	if (fd < 0 || fd > 255)
		return (-1);
	if (store[fd] == NULL)
		store[fd] = ft_strdup("");
	if (ft_strchr(store[fd], '\n') == NULL)
	{
		if ((i = read_line(fd, store, line)) == 0)
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