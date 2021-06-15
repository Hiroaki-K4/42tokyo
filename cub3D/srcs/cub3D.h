/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 21:30:52 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/15 22:03:14 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include <stdint.h>
# include <errno.h>
# include "../mlx_linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define K_W 119
# define K_S 115
# define K_D 100
# define K_A 97
# define K_ESC 65307
# define K_R 65363
# define K_L 65361

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_pair
{
	double	first;
	int		second;
}				t_pair;

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}				t_rgb;

typedef struct s_cub
{
	int			width;
	int			height;
	int			count;
	int			**map_matrix;
	int			map_x;
	int			map_y;
	int			size;
	int			floor_dec;
	int			ceiling_dec;
	int			init_pos_count;
	int			line_num;
	int			f_nowall_row;
	int			l_nowall_row;
	int			f_nowall_col;
	int			l_nowall_col;
	int			n_count;
	int			s_count;
	int			e_count;
	int			w_count;
	int			f_count;
	int			c_count;
	char		*n_texture;
	char		*s_texture;
	char		*w_texture;
	char		*e_texture;
	char		**map;
	t_rgb		floor;
	t_rgb		ceiling;
}				t_cub;

typedef struct s_info
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	movespeed;
	double	rotspeed;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	double	step;
	double	tex_pos;
	void	*mlx;
	void	*win;
	int		**buf;
	int		**texture;
	int		step_x;
	int		step_y;
	int		side;
	int		hit;
	int		line_h;
	int		mapX;
	int		mapY;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	t_img	img;
	t_cub	cub_list;
}				t_info;

int		get_next_line(int fd, char **line);
int		key_press(int key, t_info *info);
void	calc(t_info *info);
char	*ft_itoa_hex(unsigned int n, char *arg);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strchr_place(const char *str, int c);
int		cub_line_check(char *line, int count, t_info *info);
int		make_decimal_color(t_rgb color);
int		convert_int_matrix(t_info *info);
void	double_array_free(char **array);
void	error_process(char *error);
int		win_close(t_info *info);
void	double_array_free(char **array);
void	int_double_array_free(int **array, int max);
void	arg_error_check(int argc, char **argv);
void	buf_init(t_info *info, int i, int j);
void	texture_init(t_info *info, int i, int j);
void	info_init(t_info *info);
void	get_xpm_size(char *line);
void	xpm_file_check(int i, char *path);
void	load_image(t_info *info, int *texture, char *path, t_img *img);
void	load_texture(t_info *info);
int		map_edge_check(t_info *info, int *i);
void	map_not_srrounded_check(t_info *info);
void	map_space_check(t_info *info);
void	floor_check(t_info *info, char **line_split, char **rgb_split);
int		ceiling_check(t_info *info, char **line_split, char **rgb_split);
int		map_ns_check(t_info *info, char **line_split);
int		map_we_check(t_info *info, char **line_split);
void	decide_texture(t_info *info);
void	all_free(t_info *info);

#endif