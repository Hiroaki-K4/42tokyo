/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:31:11 by hkubo             #+#    #+#             */
/*   Updated: 2021/05/26 17:31:32 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int save_bmp(t_info *info)
{
	int fd;
	int filesize;
	int padding;
	
	if (!(fd = open("cub3D.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND)))
		return (-1);
	padding = (4 - (info->cub_list.width * 3) % 4) % 4;
	filesize = 54 + (3 * (info->cub_list.width + padding) * info->cub_list.height);
	write_header(fd, filesize, info);
	write_data(fd, info, padding);
	close(fd);
	printf("ok\n");
	return (0);
}