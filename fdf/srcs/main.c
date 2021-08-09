/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:21:35 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/09 16:05:07 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_fdf_file(t_info *info, char *path)
{
	int		i;
	int		fd;
	int		count;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(1);
	count = 0;
	i = 1;
	while (i > 0)
	{
		i = get_next_line(info->cub_list.fd, &line, 0);
		if (i == -1)
			exit(1);
		count++;
		printf("line: %s\n", line);
		free(line);
	}
}

int	main(int argc, char *argv[])
{
	t_info info;

	(void)argc;
	(void)argv;
	read_fdf_file(&info, argv[1]);
	return (0);
}