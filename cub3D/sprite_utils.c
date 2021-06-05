/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 11:46:18 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/05 11:48:32 by hkubo            ###   ########.fr       */
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
