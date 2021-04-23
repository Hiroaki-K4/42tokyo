/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 22:14:16 by hkubo             #+#    #+#             */
/*   Updated: 2021/04/23 21:47:57 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char *argv[])
{
	char *cub_path;

	if (argc != 2)
	{
		printf("Error\n");
		return (-1);
	}
	cub_path = argv[1];
	printf("path: %s\n", cub_path);
	argv[0] = "aa";
	return (argc);
}