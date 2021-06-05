/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:09:11 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/05 15:09:31 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	face_north(t_info *info)
{
	if (info->side == 1)
	{
		if (info->rayDirY > 0)
			info->texNum = 3;
		else
			info->texNum = 2;
	}
	else
		info->texNum = 0;
}

void	face_south(t_info *info)
{
	if (info->side == 1)
	{
		if (info->rayDirY > 0)
			info->texNum = 3;
		else
			info->texNum = 2;
	}
	else
		info->texNum = 1;
}

void	face_west(t_info *info)
{
	if (info->side == 0)
	{
		if (info->rayDirX > 0)
			info->texNum = 1;
		else
			info->texNum = 0;
	}
	else
		info->texNum = 2;
}

void	face_east(t_info *info)
{
	if (info->side == 0)
	{
		if (info->rayDirX > 0)
			info->texNum = 1;
		else
			info->texNum = 0;
	}
	else
		info->texNum = 3;
}

void	decide_texture(t_info *info)
{
	info->texNum = info->cub_list.map_matrix[info->mapX][info->mapY];
	if (info->texNum == 1)
	{
		if (fabs(info->dirX) >= fabs(info->dirY) && info->dirX <= 0)
			face_north(info);
		else if (fabs(info->dirX) >= fabs(info->dirY) && info->dirX >= 0)
			face_south(info);
		else if (fabs(info->dirY) >= fabs(info->dirX) && 0 >= info->dirY)
			face_west(info);
		else if (fabs(info->dirY) >= fabs(info->dirX) && info->dirY >= 0)
			face_east(info);
	}
}