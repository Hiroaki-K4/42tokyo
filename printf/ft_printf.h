/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:52:50 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/18 21:50:59 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

typedef	struct
{
    int flag[2];
    int field;
    int precision;
    int format;
}					a_list;

int ft_printf(const char *arg, ...);
a_list init_list();
int print_char(va_list *ap, a_list flag_list);
int print_string(va_list *ap, a_list flag_list);
int print_int(va_list *ap, a_list flag_list);
// int print_percent(va_list *ap, a_list flag_list);
int print_percent(a_list flag_list);
int print_unsigned_int(va_list *ap, a_list flag_list);
int pre_arg_zero(a_list flag_list);
int field_precision(int num, char *str, a_list flag_list);
int field_no_precision(int num, char *str, a_list flag_list);
int no_field_int(int num, char *str, a_list flag_list);
char *ft_itoa_unsigned(unsigned int n);
int print_hex(va_list *ap, a_list flag_list);
char *ft_itoa_hex(unsigned int n, char *arg);
char *ft_itoa_hex(unsigned long n, char *arg);
int print_pointer(va_list *ap, a_list flag_list);
