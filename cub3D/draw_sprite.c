/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:27:46 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/03 22:22:03 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_sprite_pos(t_info *info)
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
	if (!(info->cub_list.sprites = (t_sprite *)malloc(sizeof(t_sprite) * count)))
		error_process("Malloc failed");
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

	if (!(sprites = (t_pair*)malloc(sizeof(t_pair) * amount)))
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

void draw_sprite(t_info *info)
{
    int		i;
    int		y;
    int		d;
    int		stripe;
    int		spriteScreenX;
    int		spriteHeight;
    int		drawStartY;
    int		drawEndY;
    int		drawStartX;
    int		drawEndX;
    int		spriteWidth;
    int		texX;
    int		texY;
    int		color;
    double	spriteX;
    double	spriteY;
	double	invDet;
    double	transformX;
    double	transformY;
    int		spriteOrder[info->cub_list.num_sprites];
	double	spriteDistance[info->cub_list.num_sprites];
	
    i = 0;
	while (i < info->cub_list.num_sprites)
    {
		spriteOrder[i] = i;
		spriteDistance[i] = ((info->posX - info->cub_list.sprites[i].x) * (info->posX - info->cub_list.sprites[i].x) + (info->posY - info->cub_list.sprites[i].y) * (info->posY - info->cub_list.sprites[i].y)); //sqrt not taken, unneeded
        i++;
    }
	sortSprites(spriteOrder, spriteDistance, info->cub_list.num_sprites);
	i = 0;
	while (i < info->cub_list.num_sprites)
    {
		spriteX = info->cub_list.sprites[spriteOrder[i]].x + 0.5 - info->posX;
		spriteY = info->cub_list.sprites[spriteOrder[i]].y + 0.5 - info->posY;
		invDet = 1.0 / (info->planeX * info->dirY - info->dirX * info->planeY); //required for correct matrix multiplication
		transformX = invDet * (info->dirY * spriteX - info->dirX * spriteY);
		transformY = invDet * (-info->planeY * spriteX + info->planeX * spriteY); //this is actually the depth inside the screen, that what Z is in 3D, the distance of sprite to player, matching sqrt(spriteDistance[i])
		spriteScreenX = (int)((info->cub_list.width / 2) * (1 + transformX / transformY));
		spriteHeight = (int)fabs(info->cub_list.height / transformY); //using "transformY" instead of the real distance prevents fisheye
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
		stripe = drawStartX;
		while (stripe < drawEndX)
        {
			texX = (int)((256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texWidth / spriteWidth) / 256);
			if (transformY > 0 && stripe > 0 && stripe < info->cub_list.width && transformY < info->zBuffer[stripe])
			{
                y = drawStartY;
                while (y < drawEndY)
                {
                    d = y * 256 - info->cub_list.height * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
                    texY = ((d * texHeight) / spriteHeight) / 256;
                    color = info->texture[info->cub_list.sprites[spriteOrder[i]].texture][texWidth * texY + texX]; //get current color from the texture
                    if ((color & 0x00FFFFFF) != 0)
                        info->buf[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
                    y++;
                }
            }
            stripe++;
		}
        i++;
	}
}
