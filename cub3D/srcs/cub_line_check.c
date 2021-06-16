/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_line_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:51:54 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/16 23:04:04 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	map_line_check(t_info *info, char **line_split)
{
	int	i;
	int	j;

	if (info->cub_list.n_count != 1 || info->cub_list.s_count != 1
		|| info->cub_list.e_count != 1 || info->cub_list.w_count != 1
		|| info->cub_list.f_count != 1 || info->cub_list.c_count != 1)
		error_process(info, "Map is wrong");
	i = 0;
	while (line_split[i])
	{
		j = 0;
		while (line_split[i][j])
		{
			if (line_split[i][j] != '0' && line_split[i][j] != '1'
				&& line_split[i][j] != 'N' && line_split[i][j] != 'S'
				&& line_split[i][j] != 'E' && line_split[i][j] != 'W')
				error_process(info, "Map is wrong");
			j++;
		}
		i++;
	}
	return (0);
}

void	make_string_map(t_info *info, char **tmp, char *map_line)
{
	int	i;

	i = 0;
	while (i < info->cub_list.map_y - 1)
	{
		tmp[i] = (char *)malloc(sizeof(char)
				* (ft_strlen(info->cub_list.map[i]) + 1));
		if (tmp[i] == NULL)
			error_process(info, "Malloc failed");
		ft_strlcpy(tmp[i], info->cub_list.map[i],
			ft_strlen(info->cub_list.map[i]) + 1);
		i++;
	}
	tmp[i] = ft_strdup(map_line);
	if (tmp[i] == NULL)
		error_process(info, "ft_strdup failed");
	free(map_line);
	tmp[i + 1] = NULL;
	if (i > 0)
		double_array_free(info->cub_list.map);
	info->cub_list.map = tmp;
}

void	build_map(t_info *info, int count, char *line,
	char **line_split)
{
	char	**tmp;
	char	*map_line;

	double_array_free(line_split);
	if (info->cub_list.line_num != 0 && count - info->cub_list.line_num != 1)
		error_process(info, "Map is wrong");
	info->cub_list.line_num = count;
	info->cub_list.map_y++;
	map_line = ft_strdup(line);
	if (map_line == NULL)
		error_process(info, "ft_strdup failed");
	if ((int)ft_strlen(map_line) > info->cub_list.map_x)
		info->cub_list.map_x = ft_strlen(map_line);
	tmp = (char **)malloc(sizeof(char *) * (info->cub_list.map_y + 1));
	if (tmp == NULL)
		error_process(info, "Malloc failed");
	make_string_map(info, tmp, map_line);
}

int	cub_line_check(char *line, int count, t_info *info)
{
	int		i;
	char	**line_split;

	line_split = ft_split(line, ' ');
	if (line_split == NULL)
		error_process(info, "ft_split failed");
	i = map_ns_check(info, line_split);
	if (i == 1)
		return (0);
	i = map_we_check(info, line_split);
	if (i == 1)
		return (0);
	i = ft_strcmp("F", line_split[0]);
	if (i == 0)
	{
		floor_check(info, line_split, NULL);
		return (0);
	}
	i = ceiling_check(info, line_split, NULL);
	if (i == 1)
		return (0);
	if (map_line_check(info, line_split) == 0)
		build_map(info, count, line, line_split);
	return (0);
}
