/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:36:47 by hkubo             #+#    #+#             */
/*   Updated: 2021/06/17 17:37:15 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	save_new_line_support(char *store, char *tmp, char *buf, int i)
{
	int	j;

	j = -1;
	while (buf[++j] && (ft_strlen(store) + j + 1) < (ft_strlen(store) + i + 1))
		tmp[ft_strlen(store) + j] = buf[j];
	tmp[ft_strlen(store) + j] = '\0';
	free(store);
}
