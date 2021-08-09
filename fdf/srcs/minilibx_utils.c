/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 20:21:45 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/09 21:38:48 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	win_close(t_info *info)
{
	(void)info;
	exit(1);
	return (0);
}

int	key_press(int key, t_info *info)
{
	(void)info;
	if (key == K_ESC)
		exit(1);
	return (0);
}
