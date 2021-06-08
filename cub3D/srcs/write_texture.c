/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:40:26 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/08 21:22:41 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	dist_init(t_info *info)
{
	if (info->rayDirX < 0)
	{
		info->stepX = -1;
		info->sideDistX = (info->posX - info->mapX) * info->deltaDistX;
	}
	else
	{
		info->stepX = 1;
		info->sideDistX = (info->mapX + 1.0 - info->posX) * info->deltaDistX;
	}
	if (info->rayDirY < 0)
	{
		info->stepY = -1;
		info->sideDistY = (info->posY - info->mapY) * info->deltaDistY;
	}
	else
	{
		info->stepY = 1;
		info->sideDistY = (info->mapY + 1.0 - info->posY) * info->deltaDistY;
	}
}

void	calc_wall_height(t_info *info)
{
	while (info->hit == 0)
	{
		if (info->sideDistX < info->sideDistY)
		{
			info->sideDistX += info->deltaDistX;
			info->mapX += info->stepX;
			info->side = 0;
		}
		else
		{
			info->sideDistY += info->deltaDistY;
			info->mapY += info->stepY;
			info->side = 1;
		}
		if (info->cub_list.map_matrix[info->mapX][info->mapY] > 0
			&& info->cub_list.map_matrix[info->mapX][info->mapY] != 2)
			info->hit = 1;
	}
	if (info->side == 0)
		info->perpWallDist = (info->mapX - info->posX + (1 - info->stepX) / 2)
			/ info->rayDirX;
	else
		info->perpWallDist = (info->mapY - info->posY + (1 - info->stepY) / 2)
			/ info->rayDirY;
	info->lineHeight = (int)(info->cub_list.height / info->perpWallDist);
}

void	draw_img(t_info *info, int x, int texX)
{
	int		y;
	int		texY;
	int		color;

	y = 0;
	while (y < info->drawStart)
		info->buf[y++][x] = info->cub_list.ceiling_dec;
	y = info->drawStart;
	while (y < info->drawEnd)
	{
		texY = (int)info->texPos & (TEX_HEIGHT - 1);
		info->texPos += info->step;
		color = info->texture[info->texNum][TEX_HEIGHT * texY + texX];
		if (info->side == 1)
			color = (color >> 1) & 8355711;
		info->buf[y][x] = color;
		y++;
	}
	info->zBuffer[x] = info->perpWallDist;
	y = info->drawEnd;
	while (y < info->cub_list.height)
		info->buf[y++][x] = info->cub_list.floor_dec;
}

void	calc_loop(t_info *info, int x)
{
	int		texX;

	dist_init(info);
	calc_wall_height(info);
	info->drawStart = -info->lineHeight / 2 + info->cub_list.height / 2;
	if (info->drawStart < 0)
		info->drawStart = 0;
	info->drawEnd = info->lineHeight / 2 + info->cub_list.height / 2;
	if (info->drawEnd >= info->cub_list.height)
		info->drawEnd = info->cub_list.height - 1;
	decide_texture(info);
	if (info->side == 0)
		info->wallX = info->posY + info->perpWallDist * info->rayDirY;
	else
		info->wallX = info->posX + info->perpWallDist * info->rayDirX;
	info->wallX -= floor(info->wallX);
	texX = (int)(info->wallX * (double)TEX_WIDTH);
	if (info->side == 0 && info->rayDirX > 0)
		texX = TEX_WIDTH - texX - 1;
	if (info->side == 1 && info->rayDirY < 0)
		texX = TEX_WIDTH - texX - 1;
	info->step = 1.0 * TEX_HEIGHT / info->lineHeight;
	info->texPos = (info->drawStart - info->cub_list.height / 2
			+ info->lineHeight / 2) * info->step;
	draw_img(info, x, texX);
}

void	calc(t_info *info)
{
	int		x;

	info->zBuffer = (double *)malloc(sizeof(double) * (info->cub_list.width));
	if (!info->zBuffer)
		error_process("Malloc failed");
	x = 0;
	while (x < info->cub_list.width)
	{
		info->cameraX = 2 * x / (double)info->cub_list.width - 1;
		info->rayDirX = info->dirX + info->planeX * info->cameraX;
		info->rayDirY = info->dirY + info->planeY * info->cameraX;
		info->mapX = (int)info->posX;
		info->mapY = (int)info->posY;
		info->deltaDistX = fabs(1 / info->rayDirX);
		info->deltaDistY = fabs(1 / info->rayDirY);
		info->hit = 0;
		calc_loop(info, x);
		x++;
	}
	// if (info->cub_list.sprite_flag == 1)
	// 	draw_sprite(info);
	free(info->zBuffer);
}
