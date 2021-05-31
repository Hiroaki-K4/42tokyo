/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 21:30:52 by hkubo             #+#    #+#             */
/*   Updated: 2021/05/31 21:55:59 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
# include "mlx_linux/mlx.h"

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17
#define texWidth 64
#define texHeight 64
#define K_W 119
#define K_S 115
#define K_D 100
#define K_A 97
#define K_ESC 65307
#define K_R 65363
#define K_L 65361

typedef struct	s_sprite
{
	double		x;
	double		y;
	int			texture;
}				t_sprite;

typedef struct	s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct		s_pair
{
	double	first;
	int		second;
}					t_pair;

typedef struct		s_rgb
{
	int red;
	int green;
	int blue;
}					t_rgb;


typedef struct		s_cub
{
	int width;
	int height;
	int count;
	char **map;
	int **map_matrix;
	int map_x;
	int map_y;
	int size;
	char *n_texture;
	char *s_texture;
	char *w_texture;
	char *e_texture;
	char *sprite;
	t_sprite *sprites;
	int num_sprites;
	int sprite_flag;
	int floor_dec;
	int ceiling_dec;
	int init_pos_count;
	int line_num;
	t_rgb floor;
	t_rgb ceiling;
}					t_cub;

typedef struct	s_info
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double	*zBuffer;
	void	*mlx;
	void	*win;
	t_img	img;
	int		**buf;
	int		**texture;
	double	moveSpeed;
	double	rotSpeed;
	t_cub cub_list;
}				t_info;

int		get_next_line(int fd, char **line, int BUFFER_SIZE);
void draw_sprite(t_info *info);
int	key_press(int key, t_info *info);
void	calc(t_info *info);
char			*ft_itoa_hex(unsigned int n, char *arg);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strchr_place(const char *str, int c);
int cub_line_check(char **line, int count, t_info *info);
char *make_decimal_color(t_rgb color);
int convert_int_matrix(t_info *info);
void double_array_free(char **array);
void	error_process(char *error);
int		win_close(t_info *info);
void double_array_free(char **array);

#endif