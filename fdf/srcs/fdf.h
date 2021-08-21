/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:40:01 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/21 17:09:26 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx_linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>

# define K_ESC 65307
#define PI 3.14159265

typedef struct s_coords
{
	int	xmin;
	int	ymin;
	int	xmax;
	int	ymax;
	int	zmax;
}				t_coords;
typedef struct s_map
{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_map;

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
	double	ratio;
	void	*mlx;
	void	*win;
	t_data	img;
	t_map	**map;
	t_coords	coords;
}				t_info;

void	draw_map(t_info *info);
void	read_fdf_file(t_info *info, char *path);
void	draw_row_line(t_info *info);
void	draw_col_line(t_info *info);
void	get_coordinate(t_info *info);
void	get_ratio(t_info *info);
void	get_abs_zmax(t_info *info);
void	all_free(t_info *info, char *message);
int		win_close(t_info *info);
int		key_press(int key, t_info *info);
int		convert_hex_to_dec(char *color);
char	*get_color(char *line_split, t_info *info);

#endif
