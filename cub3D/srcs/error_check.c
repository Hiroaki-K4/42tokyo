/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 11:17:09 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/20 11:17:36 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_rgb(t_info *info, char *line, int flag)
{
	if (flag == 0)
	{
		if (info->cub_list.floor.red < 0 || info->cub_list.floor.green < 0
			|| info->cub_list.floor.blue < 0 || info->cub_list.floor.red > 255
			|| info->cub_list.floor.green > 255 || info->cub_list.floor.blue
			> 255)
		{
			get_next_line(info->cub_list.fd, &line, -1);
			free(line);
			error_process(info, "Color is wrong");
		}
	}
	else if (flag == 1)
	{
		if (info->cub_list.ceil.red < 0 || info->cub_list.ceil.green < 0
			|| info->cub_list.ceil.blue < 0 || info->cub_list.ceil.red > 255
			|| info->cub_list.ceil.green > 255 || info->cub_list.ceil.blue
			> 255)
		{
			get_next_line(info->cub_list.fd, &line, -1);
			free(line);
			error_process(info, "Color is wrong");
		}
	}
}
