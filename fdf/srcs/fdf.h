/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:40:01 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/09 21:21:47 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx_linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
#include <stdio.h>

# define K_ESC 65307

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_info
{
	int		**fdf_list;
	int		*col_count;
	int		row_count;
	int		width;
	int		height;
	int		x_start;
	int		x_end;
	int		x_step;
	int		y_start;
	int		y_end;
	int		y_step;
	void	*mlx;
	void	*win;
	t_data	img;
}				t_info;

void	draw(t_info *info);
void	read_fdf_file(t_info *info, char *path);
int		win_close(t_info *info);
int		key_press(int key, t_info *info);

#endif
