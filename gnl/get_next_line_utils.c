/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:07:04 by hkubo             #+#    #+#             */
/*   Updated: 2021/02/13 11:02:30 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*new_ptr;
	int		i;
	int		size;

	size = 0;
	while (s[size] != '\0')
		size++;
	if (!(new_ptr = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new_ptr[i] = s[i];
		i++;
	}
	new_ptr[i] = '\0';
	return (new_ptr);
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
		{
			return (char *)(s + i);
		}
		i++;
	}
	if (ptr_s[i] == '\0' && ptr_s[i] == (unsigned char)c)
	{
		return (char *)(s + i);
	}
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_size;
	size_t	i;

	printf("ssize: %ld size: %ld buf: %s\n", ft_strlen(src), size, src);
	d_size = 0;
	while (dst[d_size] != '\0' && d_size < size)
		d_size++;
	printf("ssize: %ld size: %ld buf: %s\n", ft_strlen(src), size, src);
	i = 0;
	while (src[i] != '\0' && (d_size + i + 1) < size)
	{
		dst[d_size + i] = src[i];
		i++;
	}
	printf("ssize: %ld size: %ld buf: %s\n", ft_strlen(src), size, src);
	if (d_size < size)
		dst[d_size + i] = '\0';
	printf("dsize: %ld ssize: %ld size: %ld buf: %s\n", d_size, ft_strlen(src), size, src);
	return (d_size + ft_strlen(src));
}

size_t		ft_strlen(const char *str)
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
	{
		return (ans);
	}
	i = 0;
	while (i < n - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ans);
}