/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:40:01 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/09 19:42:10 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx_linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

typedef struct s_info
{
	int		**fdf_list;
	int		*col_count;
	int		row_count;
	int		width;
	int		height;
	void	*mlx;
}				t_info;

#endif
