/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:40:26 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/13 21:17:58 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	dist_init(t_info *info)
{
	if (info->raydir_x < 0)
	{
		info->step_x = -1;
		info->sidedist_x = (info->pos_x - info->mapX) * info->deltadist_x;
	}
	else
	{
		info->step_x = 1;
		info->sidedist_x = (info->mapX + 1.0 - info->pos_x) * info->deltadist_x;
	}
	if (info->raydir_y < 0)
	{
		info->step_y = -1;
		info->sidedist_y = (info->pos_y - info->mapY) * info->deltadist_y;
	}
	else
	{
		info->step_y = 1;
		info->sidedist_y = (info->mapY + 1.0 - info->pos_y) * info->deltadist_y;
	}
}

void	calc_wall_height(t_info *info)
{
	while (info->hit == 0)
	{
		if (info->sidedist_x < info->sidedist_y)
		{
			info->sidedist_x += info->deltadist_x;
			info->mapX += info->step_x;
			info->side = 0;
		}
		else
		{
			info->sidedist_y += info->deltadist_y;
			info->mapY += info->step_y;
			info->side = 1;
		}
		if (info->cub_list.map_matrix[info->mapX][info->mapY] > 0)
			info->hit = 1;
	}
	if (info->side == 0)
		info->wall_dist = (info->mapX - info->pos_x + (1 - info->step_x) / 2)
			/ info->raydir_x;
	else
		info->wall_dist = (info->mapY - info->pos_y + (1 - info->step_y) / 2)
			/ info->raydir_y;
	info->line_h = (int)(info->cub_list.height / info->wall_dist);
}

void	draw_img(t_info *info, int x, int tex_x)
{
	int		y;
	int		tex_y;
	int		color;

	y = 0;
	while (y < info->draw_start)
		info->buf[y++][x] = info->cub_list.ceiling_dec;
	y = info->draw_start;
	while (y < info->draw_end)
	{
		tex_y = (int)info->tex_pos;
		info->tex_pos += info->step;
		color = info->texture[info->tex_num][TEX_HEIGHT * tex_y + tex_x];
		info->buf[y][x] = color;
		y++;
	}
	y = info->draw_end;
	while (y < info->cub_list.height)
		info->buf[y++][x] = info->cub_list.floor_dec;
}

void	calc_loop(t_info *info, int x)
{
	int		tex_x;

	dist_init(info);
	calc_wall_height(info);
	info->draw_start = -info->line_h / 2 + info->cub_list.height / 2;
	if (info->draw_start < 0)
		info->draw_start = 0;
	info->draw_end = info->line_h / 2 + info->cub_list.height / 2;
	if (info->draw_end >= info->cub_list.height)
		info->draw_end = info->cub_list.height - 1;
	decide_texture(info);
	if (info->side == 0)
		info->wall_x = info->pos_y + info->wall_dist * info->raydir_y;
	else
		info->wall_x = info->pos_x + info->wall_dist * info->raydir_x;
	info->wall_x -= floor(info->wall_x);
	tex_x = (int)(info->wall_x * (double)TEX_WIDTH);
	if (info->side == 0 && info->raydir_x > 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	if (info->side == 1 && info->raydir_y < 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	info->step = 1.0 * TEX_HEIGHT / info->line_h;
	info->tex_pos = (info->draw_start - info->cub_list.height / 2
			+ info->line_h / 2) * info->step;
	draw_img(info, x, tex_x);
}

void	calc(t_info *info)
{
	int		x;

	x = 0;
	while (x < info->cub_list.width)
	{
		info->camera_x = 2 * x / (double)info->cub_list.width - 1;
		info->raydir_x = info->dir_x + info->plane_x * info->camera_x;
		info->raydir_y = info->dir_y + info->plane_y * info->camera_x;
		info->mapX = (int)info->pos_x;
		info->mapY = (int)info->pos_y;
		info->deltadist_x = fabs(1 / info->raydir_x);
		info->deltadist_y = fabs(1 / info->raydir_y);
		info->hit = 0;
		calc_loop(info, x);
		x++;
	}
}
