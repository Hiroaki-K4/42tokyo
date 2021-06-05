/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:27:46 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/05 11:31:52 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	malloc_sprites(t_info *info)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < info->cub_list.map_y)
	{
		j = 0;
		while (j < info->cub_list.map_x)
		{
			if (info->cub_list.map_matrix[i][j] == 2)
				count++;
			j++;
		}
		i++;
	}
	info->cub_list.sprites = (t_sprite *)malloc(sizeof(t_sprite) * count);
	if (!info->cub_list.sprites)
		error_process("Malloc failed");
}

int	get_sprite_pos(t_info *info)
{
	int	i;
	int	j;
	int	count;

	malloc_sprites(info);
	count = 0;
	i = 0;
	while (i < info->cub_list.map_y)
	{
		j = 0;
		while (j < info->cub_list.map_x)
		{
			if (info->cub_list.map_matrix[i][j] == 2)
			{
				info->cub_list.sprites[count].x = i;
				info->cub_list.sprites[count].y = j;
				info->cub_list.sprites[count].texture = 4;
				count++;
			}
			j++;
		}
		i++;
	}
	info->cub_list.num_sprites = count;
	return (0);
}

void	sort_order(t_pair *orders, int amount)
{
	int		i;
	int		j;
	t_pair	tmp;

	i = 0;
	while (i < amount)
	{
		j = 0;
		while (j < amount - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
			j++;
		}
		i++;
	}
}

void	sortSprites(int *order, double *dist, int amount)
{
	int		i;
	t_pair	*sprites;

	sprites = (t_pair *)malloc(sizeof(t_pair) * amount);
	if (!sprites)
		error_process("Malloc failed");
	i = 0;
	while (i < amount)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
		i++;
	}
	sort_order(sprites, amount);
	i = 0;
	while (i < amount)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
		i++;
	}
	free(sprites);
}

void	insert_pixel_loop(t_info *info, int sprite, int *spriteOrder, int i)
{
	int		color;
	int		y;
	int		j;

	info->texX = (int)((256 * (sprite - (-info->spriteW / 2
					+ info->spriteScreenX)) * texWidth / info->spriteW) / 256);
	if (info->transformY > 0 && sprite > 0 && sprite < info->cub_list.width
		&& info->transformY < info->zBuffer[sprite])
	{
		y = info->drawStartY;
		while (y < info->drawEndY)
		{
			j = y * 256 - info->cub_list.height * 128 + info->spriteH * 128;
			info->texY = ((j * texHeight) / info->spriteH) / 256;
			color = info->texture[info->cub_list.sprites
			[spriteOrder[i]].texture][texWidth * info->texY + info->texX];
			if ((color & 0x00FFFFFF) != 0)
				info->buf[y][sprite] = color;
			y++;
		}
	}
}

void	insert_pixel(t_info *info, int *spriteOrder, int i)
{
	int		sprite;

	sprite = info->drawStartX;
	while (sprite < info->drawEndX)
	{
		insert_pixel_loop(info, sprite, spriteOrder, i);
		sprite++;
	}
}

void	calc_sprite(t_info *info, int *spriteOrder)
{
	int		i;

	i = 0;
	while (i < info->cub_list.num_sprites)
	{
		info->spriteX = info->cub_list.sprites[spriteOrder[i]].x + 0.5 - info->posX;
		info->spriteY = info->cub_list.sprites[spriteOrder[i]].y + 0.5 - info->posY;
		info->invDet = 1.0 / (info->planeX * info->dirY - info->dirX * info->planeY);
		info->transformX = info->invDet * (info->dirY * info->spriteX - info->dirX * info->spriteY);
		info->transformY = info->invDet * (-info->planeY * info->spriteX + info->planeX * info->spriteY);
		info->spriteScreenX = (int)((info->cub_list.width / 2) * (1 + info->transformX / info->transformY));
		info->spriteH = (int)fabs(info->cub_list.height / info->transformY);
		info->drawStartY = -info->spriteH / 2 + info->cub_list.height / 2;
		if (info->drawStartY < 0)
			info->drawStartY = 0;
		info->drawEndY = info->spriteH / 2 + info->cub_list.height / 2;
		if (info->drawEndY >= info->cub_list.height)
			info->drawEndY = info->cub_list.height - 1;
		info->spriteW = (int)fabs(info->cub_list.height / info->transformY);
		info->drawStartX = -info->spriteW / 2 + info->spriteScreenX;
		if (info->drawStartX < 0)
			info->drawStartX = 0;
		info->drawEndX = info->spriteW / 2 + info->spriteScreenX;
		if (info->drawEndX >= info->cub_list.width)
			info->drawEndX = info->cub_list.width - 1;
		insert_pixel(info, spriteOrder, i);
		i++;
	}
}

void	draw_sprite(t_info *info)
{
	int		i;
	int		*spriteOrder;
	double	*spriteDistance;

	spriteOrder = (int *)malloc(sizeof(int) * (info->cub_list.num_sprites));
	if (!spriteOrder)
		error_process("Malloc failed");
	spriteDistance = (double *)malloc(sizeof(double)
			* (info->cub_list.num_sprites));
	if (!spriteDistance)
		error_process("Malloc failed");
	i = 0;
	while (i < info->cub_list.num_sprites)
	{
		spriteOrder[i] = i;
		spriteDistance[i] = ((info->posX - info->cub_list.sprites[i].x)
				* (info->posX - info->cub_list.sprites[i].x) + (info->posY
					- info->cub_list.sprites[i].y) * (info->posY
					- info->cub_list.sprites[i].y));
		i++;
	}
	sortSprites(spriteOrder, spriteDistance, info->cub_list.num_sprites);
	free(spriteDistance);
	calc_sprite(info, spriteOrder);
	free(spriteOrder);
}
