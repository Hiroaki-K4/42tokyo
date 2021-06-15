/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:37:55 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/13 21:36:49 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	key_ws(t_info *info, int key)
{
	if (key == K_W)
	{
		if (!info->cub_list.map_matrix[(int)(info->pos_x + info->dir_x
				* info->movespeed)][(int)(info->pos_y)])
			info->pos_x += info->dir_x * info->movespeed;
		if (!info->cub_list.map_matrix[(int)(info->pos_x)][(int)(info->pos_y
				+ info->dir_y * info->movespeed)])
			info->pos_y += info->dir_y * info->movespeed;
	}
	if (key == K_S)
	{
		if (!info->cub_list.map_matrix[(int)(info->pos_x - info->dir_x
				* info->movespeed)][(int)(info->pos_y)])
			info->pos_x -= info->dir_x * info->movespeed;
		if (!info->cub_list.map_matrix[(int)(info->pos_x)][(int)(info->pos_y
				- info->dir_y * info->movespeed)])
			info->pos_y -= info->dir_y * info->movespeed;
	}
}

void	key_da(t_info *info, int key)
{
	if (key == K_D)
	{
		if (!info->cub_list.map_matrix[(int)(info->pos_x + info->plane_x
				* info->movespeed)][(int)(info->pos_y)])
			info->pos_x += info->plane_x * info->movespeed;
		if (!info->cub_list.map_matrix[(int)(info->pos_x)][(int)(info->pos_y
				+ info->plane_y * info->movespeed)])
			info->pos_y += info->plane_y * info->movespeed;
	}
	if (key == K_A)
	{
		if (!info->cub_list.map_matrix[(int)(info->pos_x - info->plane_x
				* info->movespeed)][(int)(info->pos_y)])
			info->pos_x -= info->plane_x * info->movespeed;
		if (!info->cub_list.map_matrix[(int)(info->pos_x)][(int)(info->pos_y
				- info->plane_y * info->movespeed)])
			info->pos_y -= info->plane_y * info->movespeed;
	}
}

void	key_right(t_info *info, int key)
{
	double	oldDirX;
	double	oldPlaneX;

	if (key == K_R)
	{
		oldDirX = info->dir_x;
		info->dir_x = info->dir_x * cos(-info->rotspeed) - info->dir_y
			* sin(-info->rotspeed);
		info->dir_y = oldDirX * sin(-info->rotspeed) + info->dir_y
			* cos(-info->rotspeed);
		oldPlaneX = info->plane_x;
		info->plane_x = info->plane_x * cos(-info->rotspeed) - info->plane_y
			* sin(-info->rotspeed);
		info->plane_y = oldPlaneX * sin(-info->rotspeed) + info->plane_y
			* cos(-info->rotspeed);
	}
}

int	key_press(int key, t_info *info)
{
	double	oldDirX;
	double	oldPlaneX;

	key_ws(info, key);
	key_da(info, key);
	key_right(info, key);
	if (key == K_L)
	{
		oldDirX = info->dir_x;
		info->dir_x = info->dir_x * cos(info->rotspeed) - info->dir_y
			* sin(info->rotspeed);
		info->dir_y = oldDirX * sin(info->rotspeed) + info->dir_y
			* cos(info->rotspeed);
		oldPlaneX = info->plane_x;
		info->plane_x = info->plane_x * cos(info->rotspeed) - info->plane_y
			* sin(info->rotspeed);
		info->plane_y = oldPlaneX * sin(info->rotspeed) + info->plane_y
			* cos(info->rotspeed);
	}
	if (key == K_ESC)
		all_free(info);
	return (0);
}
