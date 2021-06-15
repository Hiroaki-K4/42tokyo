/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 08:52:17 by hkubo             #+#    #+#             */
/*   Updated: 2020/11/28 19:38:42 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new_ptr;
	unsigned int	i;
	size_t			s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
	{
		if (!(new_ptr = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		new_ptr[0] = '\0';
		return (new_ptr);
	}
	if (!(new_ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		new_ptr[i] = s[start + i];
		i++;
	}
	new_ptr[i] = '\0';
	return (new_ptr);
}
