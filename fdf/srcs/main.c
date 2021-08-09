/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:21:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/09 20:19:09 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	add_new_row(t_info *info, char **line_split)
{
	int	i;
	int	*new_row;
	int	**new_fdf_list;

	printf("row_count: %d\n", info->row_count);
	new_row = (int *)malloc(sizeof(int) * (info->col_count[info->row_count]));
	if (!new_row)
		exit(1);
	i = 0;
	while (line_split[i] != NULL)
	{
		new_row[i] = ft_atoi(line_split[i]);
		i++;
	}
	new_fdf_list = (int **)malloc(sizeof(int *) * (info->row_count + 1));
	if (!new_fdf_list)
		exit(1);
	i = 0;
	while (i < info->row_count)
	{
		new_fdf_list[i] = info->fdf_list[i];
		i++;
	}
	new_fdf_list[i] = new_row;
	info->fdf_list = new_fdf_list;
}

void	store_fdf_value(t_info *info, char *line)
{
	int	i;
	int	count;
	int	*col_count;
	char **line_split;

	printf("len: %d\n", info->row_count);
	// printf("fdf: %s\n", line);
	line_split = ft_split(line, ' ');
	if (!line_split)
		exit(1);
	count = 0;
	while (line_split[count] != NULL)
		count++;
	printf("row: %d\n", count);
	col_count = (int *)malloc(sizeof(int) * (info->row_count + 1));
	if (!col_count)
		exit(1);
	i = 0;
	while (i < info->row_count)
	{
		col_count[i] = info->col_count[i];
		i++;
	}
	col_count[i] = count;
	if (info->row_count > 0)
		free(info->col_count);
	info->col_count = col_count;
	add_new_row(info, line_split);
}

void	read_fdf_file(t_info *info, char *path)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(1);
	i = 1;
	while (i > 0)
	{
		i = get_next_line(fd, &line, 0);
		if (i == -1)
			exit(1);
		store_fdf_value(info, line);
		info->row_count++;
		// printf("line: %s\n", line);
		free(line);
	}
	i = 0;
	while (i < info->row_count)
	{
		j = 0;
		while (j < info->col_count[i])
		{
			printf("%d", info->fdf_list[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	init_info(t_info *info)
{
	int	size_x;
	int	size_y;

	// info->win = NULL;
	// info->img.img = NULL;
	// info->mlx = NULL;
	info->row_count = 0;
	info->mlx = mlx_init();
	mlx_get_screen_size(info->mlx, &size_x, &size_y);
	info->width = size_x;
	info->height = size_y;
	printf("width: %d height: %d\n", info->width, info->height);
}

void	draw(t_info *info)
{
	(void)info;
}

int	win_close(t_info *info)
{
	(void)info;
	exit(1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_info info;

	(void)argc;
	init_info(&info);
	read_fdf_file(&info, argv[1]);
	info.win = mlx_new_window(info.mlx, info.width, info.height, "fdf");
	info.img.img = mlx_new_image(info.mlx, info.width, info.height);
	info.img.addr = mlx_get_data_addr(info.img.img, &info.img.bits_per_pixel,
			&info.img.line_length, &info.img.endian);
	mlx_hook(info.win, 33, 1 << 17, &win_close, &info);
	mlx_loop(info.mlx);
	draw(&info);
	return (0);
}