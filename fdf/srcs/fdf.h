/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:40:01 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/09 19:57:22 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx_linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_info
{
	int		**fdf_list;
	int		*col_count;
	int		row_count;
	int		width;
	int		height;
	void	*mlx;
	void	*win;
	t_img	img;
}				t_info;

#endif
