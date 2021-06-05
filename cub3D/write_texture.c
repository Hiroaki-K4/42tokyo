/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:40:26 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/05 11:51:12 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calc(t_info *info)
{
	int		x;
	int		y;
	int		stepX;
	int		stepY;
	int		side;
	int		hit;
	int		mapX;
	int		mapY;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		texNum;
	int		texX;
	int		texY;
	int		color;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	double	wallX;
	double	step;
	double	texPos;

	info->zBuffer = (double *)malloc(sizeof(double) * (info->cub_list.width));
	if (!info->zBuffer)
		error_process("Malloc failed");
	x = 0;
	while (x < info->cub_list.width)
	{
		cameraX = 2 * x / (double)info->cub_list.width - 1;
		rayDirX = info->dirX + info->planeX * cameraX;
		rayDirY = info->dirY + info->planeY * cameraX;
		mapX = (int)info->posX;
		mapY = (int)info->posY;
		deltaDistX = fabs(1 / rayDirX);
		deltaDistY = fabs(1 / rayDirY);
		hit = 0;
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (info->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - info->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (info->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - info->posY) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (info->cub_list.map_matrix[mapX][mapY] > 0 && info->cub_list.map_matrix[mapX][mapY] != 2)
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;
		lineHeight = (int)(info->cub_list.height / perpWallDist);
		drawStart = -lineHeight / 2 + info->cub_list.height / 2;
		if(drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + info->cub_list.height / 2;
		if(drawEnd >= info->cub_list.height)
			drawEnd = info->cub_list.height - 1;
		texNum = info->cub_list.map_matrix[mapX][mapY];
		if (texNum == 1)
		{
			if (fabs(info->dirX) >= fabs(info->dirY) && info->dirX <= 0)
			{
				if (side == 1)
				{
					if (rayDirY > 0)
						texNum = 3;
					else
						texNum = 2;
				}
				else
					texNum = 0;
			}
			else if (fabs(info->dirX) >= fabs(info->dirY) && info->dirX >= 0)
			{
				if (side == 1)
				{
					if (rayDirY > 0)
						texNum = 3;
					else
						texNum = 2;
				}
				else
					texNum = 1;
			}
			else if (fabs(info->dirY) >= fabs(info->dirX) && 0 >= info->dirY)
			{
				if (side == 0)
				{
					if (rayDirX > 0)
						texNum = 1;
					else
						texNum = 0;
				}
				else
					texNum = 2;
			}
			else if (fabs(info->dirY) >= fabs(info->dirX) && info->dirY >= 0)
			{
				if (side == 0)
				{
					if (rayDirX > 0)
						texNum = 1;
					else
						texNum = 0;
				}
				else
					texNum = 3;
			}
		}
		if (side == 0)
			wallX = info->posY + perpWallDist * rayDirY;
		else
			wallX = info->posX + perpWallDist * rayDirX;
		wallX -= floor(wallX);
		texX = (int)(wallX * (double)texWidth);
		if (side == 0 && rayDirX > 0)
			texX = texWidth - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = texWidth - texX - 1;
		step = 1.0 * texHeight / lineHeight;
		texPos = (drawStart - info->cub_list.height / 2 + lineHeight / 2) * step;
		y = 0;
		while (y < drawStart)
		{
			info->buf[y][x] = info->cub_list.ceiling_dec;
			y++;
		}
		y = drawStart;
		while (y < drawEnd)
		{
			texY = (int)texPos & (texHeight - 1);
			texPos += step;
			color = info->texture[texNum][texHeight * texY + texX];
			if (side == 1)
				color = (color >> 1) & 8355711;
			info->buf[y][x] = color;
			y++;
		}
		info->zBuffer[x] = perpWallDist;
		y = drawEnd;
		while (y < info->cub_list.height)
		{
			info->buf[y][x] = info->cub_list.floor_dec;
			y++;
		}
		x++;
	}
	if (info->cub_list.sprite_flag == 1)
		draw_sprite(info);
	free(info->zBuffer);
}
