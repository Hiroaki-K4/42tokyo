/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fdf_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 20:24:50 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/20 22:48:11 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_new_row(t_info *info, char **line_split)
{
	int	i;
	t_map	*new_row;
	t_map	**new_map;

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
		new_row[i].color = convert_hex_to_dec(get_color(line_split[i]));
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

	line_split = ft_split(line, ' ');
	if (!line_split)
		exit(1);
	count = 0;
	while (line_split[count] != NULL)
		count++;
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

void	col_num_check(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->row_count - 1)
	{
		if (info->col_count[i] != info->col_count[i + 1])
		{
			printf("Error\n");
			exit(1);
		}
		printf("col: %d\n", info->col_count[i]);
		i++;
	}
}

void	read_fdf_file(t_info *info, char *path)
{
	int		i;
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
	col_num_check(info);
}
