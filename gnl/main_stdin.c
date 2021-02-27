/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 06:38:23 by user42            #+#    #+#             */
/*   Updated: 2021/02/27 15:36:10 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		i;
	int		fd;
	char	*get_line;

	i = 0;
	fd = 0;
	while (i++ < 5)
	{
		printf("%d\n", get_next_line(fd, &get_line));
		printf("%s\n", get_line);
		free(get_line);
	}
	return (0);
}
