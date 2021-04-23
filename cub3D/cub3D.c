/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 22:14:16 by hkubo             #+#    #+#             */
/*   Updated: 2021/04/23 21:45:57 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char *argv[])
{
	char *str;
	int i;

	if (argc != 2)
	{
		printf("Error\n");
		return (-1);
	}
	str = "aaa";
	i = ft_strlen(str);
	argv[0] = "aa";
	printf("len: %d\n", i);
	return (argc);
}