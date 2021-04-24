/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 22:14:16 by hkubo             #+#    #+#             */
/*   Updated: 2021/04/24 10:56:33 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char *argv[])
{
	int i;
	int fd;
	int buffer_size;
	char *line;
	char *cub_path;
	void    *mlx;
    void    *img;

	if (argc != 2)
	{
		printf("Error\n");
		return (-1);
	}
	buffer_size = 10;
    fd = open(argv[1], O_RDONLY);
	do
	{
		i = get_next_line(fd, &line, buffer_size);
		printf("~~~fd: %d line: %s return: %d~~~\n", fd, line, i);
		free(line);
	} while (i > 0);
	cub_path = argv[1];
	i = ft_strlen(cub_path);
	printf("len: %i\n", i);
	printf("path: %s\n", cub_path);
	argv[0] = "aa";
	mlx = mlx_init();
	img = mlx_new_image(mlx, 1920, 1080);
	return (argc);
}