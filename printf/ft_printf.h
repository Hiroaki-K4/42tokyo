/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:52:50 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/08 11:23:13 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"

typedef	struct
{
    int flag[2];
    int field;
    int precision;
    int format;
}					a_list;

int ft_printf(const char *arg, ...);
a_list init_list(a_list flag_list);