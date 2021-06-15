/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 12:01:33 by hkubo             #+#    #+#             */
/*   Updated: 2020/11/28 19:44:15 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char const	*ptr_src;
	size_t				i;

	ptr_src = (unsigned char const *)s;
	i = 0;
	while (i < n)
	{
		if (ptr_src[i] == (unsigned char)c)
			return (void *)(s + i);
		i++;
	}
	return (NULL);
}
