/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:31:11 by hkubo             #+#    #+#             */
/*   Updated: 2021/05/27 08:48:34 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void set_int_as_char(unsigned char *str, int num)
// {
// 	str[0] = (unsigned char)(num);
// 	str[1] = (unsigned char)(num >> 8);
// 	str[2] = (unsigned char)(num >> 16);
// 	str[3] = (unsigned char)(num >> 24);
// }

// int write_header(int fd, int filesize, t_info *info)
// {
// 	int num;
// 	unsigned char bitmapfileheader[54];
	
// 	ft_bzero(bitmapfileheader, 54);
// 	bitmapfileheader[0] = (unsigned char)('B');
// 	bitmapfileheader[1] = (unsigned char)('M');
// 	set_int_as_char(bitmapfileheader + 2, filesize);
// 	bitmapfileheader[10] = (unsigned char)(54);
// 	bitmapfileheader[14] = (unsigned char)(40);
// 	num = info->cub_list.width;
// 	set_int_as_char(bitmapfileheader + 18, num);
// 	num = info->cub_list.height;
// 	set_int_as_char(bitmapfileheader + 22, num);
// 	bitmapfileheader[27] = (unsigned char)(1);
// 	bitmapfileheader[28] = (unsigned char)(24);
// 	write(fd, bitmapfileheader, 54);
// 	return (0);
// }

// int write_data(int fd, t_info *info, int padding)
// {
// 	int i;
// 	int j;
// 	int color;
// 	unsigned char zero[3] = {0, 0, 0};

// 	j = 0;
// 	while (info->cub_list.height > j)
// 	{
// 		i = 0;
// 		while (info->cub_list.width > i)
// 		{
// 			color = info->img.data[i + (info->cub_list.height - 1 - j) * info->cub_list.width];
// 			write(fd, &color, 3);
// 			i++;
// 		}
// 		i = -1;
// 		while (++i < (4 - (info->cub_list.width * 3) % 4) % 4)
// 			write(fd, &zero, 1);
// 		j++;
// 	}
	
// }

// int save_bmp(t_info *info)
// {
// 	int fd;
// 	int filesize;
// 	int padding;
	
// 	if (!(fd = open("cub3D.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND)))
// 		return (-1);
// 	padding = (4 - (info->cub_list.width * 3) % 4) % 4;
// 	filesize = 54 + (3 * (info->cub_list.width + padding) * info->cub_list.height);
// 	write_header(fd, filesize, info);
// 	write_data(fd, info, padding);
// 	close(fd);
// 	return (0);
// }