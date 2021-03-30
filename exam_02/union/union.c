/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:17:24 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/30 22:21:29 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char const	*ptr_s;
	int					i;

	ptr_s = (unsigned char const *)s;
	i = 0;
	while (ptr_s[i])
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
	int		i;
	int		j;
	int		flag;
	char	*arg1;
	char	*arg2;

	if (argc == 3)
	{
		arg1 = argv[1];
		arg2 = argv[2];
		i = 0;
		while (arg1[i])
		{
			flag = 1;
			j = i;
			while (j > 0)
			{
				if (arg1[j - 1] == arg1[i])
					flag = 0;
				j--;
			}
			if (flag == 1)
				write(1, &arg1[i], 1);
			i++;
		}
		i = 0;
		while (arg2[i])
		{
			if (ft_strchr(arg1, arg2[i]) == NULL)
			{
				flag = 1;
				j = i;
				while (j > 0)
				{
					if (arg2[j - 1] == arg2[i])
						flag = 0;
					j--;
				}
				if (flag == 1)
					write(1, &arg2[i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
