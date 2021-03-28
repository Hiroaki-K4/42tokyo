/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 06:38:23 by user42            #+#    #+#             */
/*   Updated: 2021/03/28 18:35:44 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	int		r;
	char	*get_line;

	(void)argc;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (i++ < 5)
	{
		r = get_next_line(fd, &get_line);
		printf("%d\n", r);
		if (r == -1)
		{
			break ;
		}
		printf("%s\n", get_line);
		free(get_line);
	}
	close(fd);
	return (0);
}
