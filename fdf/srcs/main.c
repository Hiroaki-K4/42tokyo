/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:21:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/09 16:50:11 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	store_fdf_value(t_info *info, char *line)
{
	printf("len: %d\n", info->line);
	printf("fdf: %s\n", line);
	
}

void	read_fdf_file(t_info *info, char *path)
{
	int		i;
	int		fd;
	int		count;
	char	*line;

	(void)info;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(1);
	count = 0;
	i = 1;
	while (i > 0)
	{
		i = get_next_line(fd, &line, 0);
		if (i == -1)
			exit(1);
		count++;
		store_fdf_value(info, line);
		printf("line: %s\n", line);
		free(line);
	}
}

void	init_info(t_info *info)
{
	info->line = 0;
}

int	main(int argc, char *argv[])
{
	t_info info;

	(void)argc;
	(void)argv;
	init_info(&info);
	read_fdf_file(&info, argv[1]);
	return (0);
}