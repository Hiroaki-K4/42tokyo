/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:27:46 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/04 22:33:50 by hkubo            ###   ########.fr       */
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

void	insert_pixel(t_info *info, int *spriteOrder)
{
	int		i;
	int		y;
	int		d;
	double	spriteX;
	double	spriteY;
	double	invDet;
	double	transformX;
	double	transformY;
	int		spriteScreenX;
	int		spriteHeight;
	int		spriteWidth;
	int		drawStartY;
	int		drawEndY;
	int		drawStartX;
	int		drawEndX;
	int		sprite;
	int		texX;
	int		texY;
	int		color;

	i = 0;
	while (i < info->cub_list.num_sprites)
	{
		spriteX = info->cub_list.sprites[spriteOrder[i]].x + 0.5 - info->posX;
		spriteY = info->cub_list.sprites[spriteOrder[i]].y + 0.5 - info->posY;
		invDet = 1.0 / (info->planeX * info->dirY - info->dirX * info->planeY);
		transformX = invDet * (info->dirY * spriteX - info->dirX * spriteY);
		transformY = invDet * (-info->planeY * spriteX + info->planeX * spriteY);
		spriteScreenX = (int)((info->cub_list.width / 2) * (1 + transformX / transformY));
		spriteHeight = (int)fabs(info->cub_list.height / transformY);
		drawStartY = -spriteHeight / 2 + info->cub_list.height / 2;
		if (drawStartY < 0)
			drawStartY = 0;
		drawEndY = spriteHeight / 2 + info->cub_list.height / 2;
		if (drawEndY >= info->cub_list.height)
			drawEndY = info->cub_list.height - 1;
		spriteWidth = (int)fabs(info->cub_list.height / transformY);
		drawStartX = -spriteWidth / 2 + spriteScreenX;
		if (drawStartX < 0)
			drawStartX = 0;
		drawEndX = spriteWidth / 2 + spriteScreenX;
		if (drawEndX >= info->cub_list.width)
			drawEndX = info->cub_list.width - 1;
		sprite = drawStartX;
		while (sprite < drawEndX)
		{
			texX = (int)((256 * (sprite - (-spriteWidth / 2 + spriteScreenX)) * texWidth / spriteWidth) / 256);
			if (transformY > 0 && sprite > 0 && sprite < info->cub_list.width && transformY < info->zBuffer[sprite])
			{
				y = drawStartY;
				while (y < drawEndY)
				{
					d = y * 256 - info->cub_list.height * 128 + spriteHeight * 128;
					texY = ((d * texHeight) / spriteHeight) / 256;
					color = info->texture[info->cub_list.sprites[spriteOrder[i]].texture][texWidth * texY + texX];
					if ((color & 0x00FFFFFF) != 0)
						info->buf[y][sprite] = color;
					y++;
				}
			}
			sprite++;
		}
		i++;
	}
}

void	draw_sprite(t_info *info)
{
	int		i;
	// int		spriteOrder[info->cub_list.num_sprites];
	int		*spriteOrder;
	// double	spriteDistance[info->cub_list.num_sprites];
	double	*spriteDistance;

	spriteOrder = (int *)malloc(sizeof(int) * (info->cub_list.num_sprites));
	if (!spriteOrder)
		error_process("Malloc failed");
	spriteDistance = (double *)malloc(sizeof(double) * (info->cub_list.num_sprites));
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
	insert_pixel(info, spriteOrder);
}
