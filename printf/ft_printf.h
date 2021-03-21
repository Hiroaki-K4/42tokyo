/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:52:50 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/21 22:08:00 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include "libft/libft.h"

typedef	struct
{
	int flag[2];
	int field;
	int precision;
	int format;
}		t_plist;

int		ft_printf(const char *arg, ...);
int		print_char(va_list *ap, t_plist flag_list, int len);
int		print_string(va_list *ap, t_plist flag_list);
int		print_int(va_list *ap, t_plist flag_list);
int		print_percent(t_plist flag_list);
int		print_unsigned_int(va_list *ap, t_plist flag_list);
int		pre_arg_zero(t_plist flag_list);
int		field_precision(int num, char *str, t_plist flag_list);
int		field_no_precision(int num, char *str, t_plist flag_list);
int		no_field_int(int num, char *str, t_plist flag_list);
char	*ft_itoa_unsigned(unsigned int n);
int		print_hex(va_list *ap, t_plist flag_list);
char	*ft_itoa_hex(unsigned int n, char *arg);
char	*ft_itoa_hex_long(unsigned long n, char *arg);
int		print_pointer(va_list *ap, t_plist flag_list);
int		str_to_num_field(const char *arg, int *i, va_list *ap, t_plist *f_list);
int		str_to_num_pre(const char *arg, int *i, va_list *ap, int k);
t_plist	init_plist(void);
int		get_len_long(unsigned long n);

#endif
