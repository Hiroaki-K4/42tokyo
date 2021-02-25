/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 06:38:23 by user42            #+#    #+#             */
/*   Updated: 2020/07/03 14:46:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
