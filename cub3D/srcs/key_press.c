/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:37:55 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/03 21:47:43 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	key_ws(t_info *info, int key)
{
	if (key == K_W)
	{
		if (!info->cub_list.map_matrix[(int)(info->posX + info->dirX
				* info->moveSpeed)][(int)(info->posY)])
			info->posX += info->dirX * info->moveSpeed;
		if (!info->cub_list.map_matrix[(int)(info->posX)][(int)(info->posY
				+ info->dirY * info->moveSpeed)])
			info->posY += info->dirY * info->moveSpeed;
	}
	if (key == K_S)
	{
		if (!info->cub_list.map_matrix[(int)(info->posX - info->dirX
				* info->moveSpeed)][(int)(info->posY)])
			info->posX -= info->dirX * info->moveSpeed;
		if (!info->cub_list.map_matrix[(int)(info->posX)][(int)(info->posY
				- info->dirY * info->moveSpeed)])
			info->posY -= info->dirY * info->moveSpeed;
	}
}

void	key_da(t_info *info, int key)
{
	if (key == K_D)
	{
		if (!info->cub_list.map_matrix[(int)(info->posX + info->planeX
				* info->moveSpeed)][(int)(info->posY)])
			info->posX += info->planeX * info->moveSpeed;
		if (!info->cub_list.map_matrix[(int)(info->posX)][(int)(info->posY
				+ info->planeY * info->moveSpeed)])
			info->posY += info->planeY * info->moveSpeed;
	}
	if (key == K_A)
	{
		if (!info->cub_list.map_matrix[(int)(info->posX - info->planeX
				* info->moveSpeed)][(int)(info->posY)])
			info->posX -= info->planeX * info->moveSpeed;
		if (!info->cub_list.map_matrix[(int)(info->posX)][(int)(info->posY
				- info->planeY * info->moveSpeed)])
			info->posY -= info->planeY * info->moveSpeed;
	}
}

void	key_right(t_info *info, int key)
{
	double	oldDirX;
	double	oldPlaneX;

	if (key == K_R)
	{
		oldDirX = info->dirX;
		info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY
			* sin(-info->rotSpeed);
		info->dirY = oldDirX * sin(-info->rotSpeed) + info->dirY
			* cos(-info->rotSpeed);
		oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY
			* sin(-info->rotSpeed);
		info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY
			* cos(-info->rotSpeed);
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
		oldDirX = info->dirX;
		info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY
			* sin(info->rotSpeed);
		info->dirY = oldDirX * sin(info->rotSpeed) + info->dirY
			* cos(info->rotSpeed);
		oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY
			* sin(info->rotSpeed);
		info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY
			* cos(info->rotSpeed);
	}
	if (key == K_ESC)
		exit(0);
	return (0);
}