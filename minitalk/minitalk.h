/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:05:16 by hkubo             #+#    #+#             */
/*   Updated: 2021/08/08 17:07:03 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>
# include "libft/libft.h"

int	g_bit_store[8];

int	bit_to_ascii(void);
int	binary_pow(int a, int b);

#endif
