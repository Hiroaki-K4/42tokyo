/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 22:14:16 by hkubo             #+#    #+#             */
/*   Updated: 2021/04/24 15:12:16 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

// int             key_hook(int keycode, t_vars *vars)
// {
// 	printf("keycode: %d\n", keycode);
//     printf("Hello from key_hook!\n");
// }

int             key_press(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

// int             resize_display(int keycode, t_vars *vars)
// {
// 	printf("Resize display");
// 	return (0);
// }

// void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
//     char    *dst;

//     dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//     *(unsigned int*)dst = color;
// }

int main_loop(void *arg)
{
	return (0);
}

int	main(int argc, char *argv[])
{
	int i;
	int fd;
	int buffer_size;
	char *line;
	char *cub_path;
	void    *mlx;
	void    *mlx_win;
	t_data  img;
	t_vars      vars;

	if (argc != 2)
	{
		printf("Error\n");
		return (-1);
	}
	buffer_size = 10;
    fd = open(argv[1], O_RDONLY);
	do
	{
		i = get_next_line(fd, &line, buffer_size);
		printf("~~~fd: %d line: %s return: %d~~~\n", fd, line, i);
		free(line);
	} while (i > 0);
	cub_path = argv[1];
	i = ft_strlen(cub_path);
	printf("len: %i\n", i);
	printf("path: %s\n", cub_path);
	argv[0] = "aa";
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    // img.img = mlx_new_image(mlx, 1920, 1080);
    // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
    //                             &img.endian);
    // my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// my_mlx_pixel_put(&img, 10, 10, 0x00FFFF00);
    // mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    // mlx_loop(mlx);
	
	// vars.mlx = mlx_init();
    // vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
    // mlx_key_hook(vars.win, key_hook, &vars);
    // mlx_loop(vars.mlx);
	
	vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, screenWidth, screenHeight, "Raycaster!");
	mlx_loop_hook(vars.mlx, main_loop, &vars);
    mlx_hook(vars.win, 2, 1L<<0, key_press, &vars);
    // mlx_hook(vars.win, 2, 1L<<18, resize_display, &vars);
    mlx_loop(vars.mlx);
	// return (argc);
}