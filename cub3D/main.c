/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 22:14:16 by hkubo             #+#    #+#             */
/*   Updated: 2021/04/23 21:16:38 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char *str;
	int i;

	str = "aaa";
	i = ft_strlen(str);
	argv[0] = "aa";
	printf("len: %d\n", i);
	return (argc);
}