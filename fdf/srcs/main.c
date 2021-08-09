/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:21:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/09 17:55:06 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	add_new_row(t_info *info, char *line, char **line_split)
{
	int	i;
	int	*new_row;
	int	**new_fdf_list;

	(void)info;
	(void)line;
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
	i = 0;
	while (i < info->row_count)
	{
		free(info->fdf_list[i]);
		i++;
	}
	// free(info->fdf_list);
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
	add_new_row(info, line, line_split);
}

void	read_fdf_file(t_info *info, char *path)
{
	int		i;
	int		fd;
	char	*line;

	(void)info;
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
}

void	init_info(t_info *info)
{
	info->row_count = 0;
}

int	main(int argc, char *argv[])
{
	t_info info;

	(void)argc;
	init_info(&info);
	read_fdf_file(&info, argv[1]);
	return (0);
}