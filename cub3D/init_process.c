/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:47:50 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/01 11:48:19 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	arg_error_check(int argc, char **argv)
{
	int i;

	if (argc != 2)
		error_process("The number of arguments is wrong");
	i = ft_strlen(argv[1]);
	if ((i = ft_strlen(argv[1])) < 5)
		error_process("Map file is wrong");
	if (strcmp(&argv[1][i - 4], ".cub") != 0)
		error_process("Not a cub file");
}