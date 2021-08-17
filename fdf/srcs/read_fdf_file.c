/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fdf_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 20:24:50 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/17 23:03:19 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_new_row(t_info *info, char **line_split)
{
	int	i;
	int	*new_row;
	int	**new_fdf_list;

	// printf("row_count: %d\n", info->row_count);
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

int	check_color_hex(char *color)
{
	int	i;

	if (color[0] != '0' || color[1] != 'x')
		return (-1);
	i = 2;
	while (i < 8)
	{
		if (ft_isdigit(color[i]) != 1 && (color[i] < 'A' || color[i] > 'F') && (color[i] < 'a' || color[i] > 'f'))
			return (-1);
		i++;
	}
	return (0);
}

char	*get_color(char *line_split)
{
	char	*color;

	color = ft_strchr(line_split, ',');
	if (color != NULL)
	{
		if (ft_strlen(color) == 9)
		{
			color++;
			if (check_color_hex(color) == -1)
				exit(1);
		}
		else
			exit(1);
	}
	else
		color = "0x00FFFFFF";
	return (color);
}

void	add_new_row2(t_info *info, char **line_split)
{
	int	i;
	t_map	*new_row;
	t_map	**new_map;

	// printf("row_count: %d\n", info->row_count);
	new_map = (t_map **)malloc(sizeof(t_map *) * (info->row_count + 1));
	if (!new_map)
		exit(1);
	i = 0;
	while (i < info->row_count)
	{
		new_map[i] = info->map[i];
		i++;
	}
	new_row = (t_map *)malloc(sizeof(t_map) * (info->col_count[info->row_count]));
	if (!new_row)
		exit(1);
	i = 0;
	while (line_split[i] != NULL)
	{
		new_row[i].x = i;
		new_row[i].y = info->row_count;
		new_row[i].z = ft_atoi(line_split[i]);
		new_row[i].color = get_color(line_split[i]);
		i++;
	}
	new_map[info->row_count] = new_row;
	info->map = new_map;
}

void	store_fdf_value(t_info *info, char *line)
{
	int	i;
	int	count;
	int	*col_count;
	char **line_split;

	// printf("len: %d\n", info->row_count);
	// printf("fdf: %s\n", line);
	line_split = ft_split(line, ' ');
	// printf("line_split: %s\n", line_split[0]);
	if (!line_split)
		exit(1);
	count = 0;
	while (line_split[count] != NULL)
		count++;
	// printf("row: %d\n", count);
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
	add_new_row2(info, line_split);
}

void	read_fdf_file(t_info *info, char *path)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	info->row_count = 0;
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
		free(line);
	}
	// printf("col_count: %d\n", info->col_count[0]);
	i = 0;
	while (i < info->row_count)
	{
		j = 0;
		while (j < info->col_count[i])
		{
			// printf("%d", info->fdf_list[i][j]);
			// printf("%d", info->map[i][j].y);
			j++;
		}
		// printf("\n");
		i++;
	}
}
