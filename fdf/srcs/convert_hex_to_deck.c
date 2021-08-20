/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex_to_deck.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 18:31:52 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/20 18:32:14 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_strchr_place(const char *arg, int c)
{
	int j;

	j = 0;
	while (arg[j])
	{
		if (arg[j] == c)
			return (j);
		j++;
	}
	return (-1);
}

int	convert_calc(int a, int b, char word)
{
	int	ans;
	int	pos;

	pos = ft_strchr_place("0123456789ABCDEF", word);
	if (pos == -1)
		pos = ft_strchr_place("0123456789abcdef", word);
	if (pos == -1)
		exit(1);
	ans = 1;
	// if (b == 0)
		// return (1);
	while (b > 0)
	{
		ans = ans * a;
		b--;
	}
	ans = ans * pos;
	return (ans);
}

int	convert_hex_to_dec(char *color)
{
	int	i;
	int	dec;

	printf("color: %s\n", color);
	dec = 0;
	i = 2;
	while (i < 8 && color[i])
	{
		dec += convert_calc(16, 7 - i, color[i]);
		i++;
	}
	printf("color: %s dec: %d\n", color, dec);
	return (dec);
}
