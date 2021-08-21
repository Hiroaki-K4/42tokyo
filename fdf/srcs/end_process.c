/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 20:21:45 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/21 16:21:01 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	all_free_mlx(t_info *info)
{
	if (info->win)
		mlx_destroy_window(info->mlx, info->win);
	if (info->img.img)
		mlx_destroy_image(info->mlx, info->img.img);
	if (info->mlx)
	{
		mlx_destroy_display(info->mlx);
		free(info->mlx);
	}
}

void	all_free(t_info *info, char *message)
{
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
	// if (info->buf)
	// 	int_double_array_free(info->buf, info->cub_list.height);
	// if (info->texture)
	// 	int_double_array_free(info->texture, 4);
	// if (info->cub_list.map_matrix)
	// 	int_double_array_free(info->cub_list.map_matrix, info->cub_list.map_y);
	// if (info->cub_list.map)
	// 	double_array_free(info->cub_list.map);
	// if (info->cub_list.n_texture)
	// 	free(info->cub_list.n_texture);
	// if (info->cub_list.s_texture)
	// 	free(info->cub_list.s_texture);
	// if (info->cub_list.e_texture)
	// 	free(info->cub_list.e_texture);
	// if (info->cub_list.w_texture)
	// 	free(info->cub_list.w_texture);
	all_free_mlx(info);
	exit(0);
}

int	win_close(t_info *info)
{
	all_free(info, "win_close");
	return (0);
}

int	key_press(int key, t_info *info)
{
	if (key == K_ESC)
		all_free(info, "key_press");
	return (0);
}
