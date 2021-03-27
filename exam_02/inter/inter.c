/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:15:09 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/27 21:14:36 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

int main(int argc, char *argv[])
{
	char	*arg1;
	char	*arg2;
	int		i;
	int		j;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	arg1 = argv[1];
	arg2 = argv[2];
	i = 0;
	while (arg1[i])
	{
		if (ft_strchr(arg2, arg1[i]))
		{
			j = i;
			while (j > 0)
			{
				if (arg1[j - 1] != arg1[i])
				{
					write(1, &arg1[i], 1);
					break;
				}
				j--;
			}
		}
		i++;
	}
	write(1, "\n", 1);
	// printf("arg1: %s agc2: %s\n", arg1, arg2);
	return (0);
}