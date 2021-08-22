/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fdf_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 20:24:50 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/22 10:48:44 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_new_row(t_info *info, char **line_split)
{
	int		i;
	t_map	*new_row;
	t_map	**new_map;

	new_map = (t_map **)malloc(sizeof(t_map *) * (info->row_count + 1));
	if (!new_map)
		all_free(info, "[End process] add_new_row\n");
	i = -1;
	while (++i < info->row_count)
		new_map[i] = info->map[i];
	new_row = (t_map *)malloc(sizeof(t_map)
			* (info->col_count[info->row_count]));
	if (!new_row)
		all_free(info, "[End process] add_new_row\n");
	i = -1;
	while (line_split[++i] != NULL)
	{
		new_row[i].x = i;
		new_row[i].y = info->row_count;
		new_row[i].z = ft_atoi(line_split[i]);
		new_row[i].color = hex_to_dec(get_color(line_split[i], info), info);
	}
	new_map[info->row_count] = new_row;
	free(info->map);
	info->map = new_map;
}

void	store_fdf_value(t_info *info, char *line)
{
	int		i;
	int		count;
	int		*col_count;
	char	**line_split;

	line_split = ft_split(line, ' ');
	if (!line_split)
		all_free(info, "[End process] store_fdf_value\n");
	count = 0;
	while (line_split[count] != NULL)
		count++;
	col_count = (int *)malloc(sizeof(int) * (info->row_count + 1));
	if (!col_count)
		all_free(info, "[End process] store_fdf_value\n");
	i = -1;
	while (++i < info->row_count)
		col_count[i] = info->col_count[i];
	col_count[i] = count;
	if (info->row_count > 0)
		free(info->col_count);
	info->col_count = col_count;
	add_new_row(info, line_split);
	free_double_array(line_split);
}

void	col_num_check(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->row_count - 1)
	{
		if (info->col_count[i] != info->col_count[i + 1]
			&& info->col_count[i + 1] != 0)
			all_free(info, "[End process] col_num_check\n");
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
		all_free(info, "[End process] read_fdf_file\n");
	i = 1;
	while (i > 0)
	{
		i = get_next_line(fd, &line, 0);
		if (i == -1)
			all_free(info, "[End process] read_fdf_file\n");
		store_fdf_value(info, line);
		info->row_count++;
		free(line);
	}
	col_num_check(info);
}
