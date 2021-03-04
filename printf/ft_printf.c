/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:39:32 by hkubo             #+#    #+#             */
/*   Updated: 2021/03/04 10:39:32 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_printf_str(const char *arg, int i)
{
    while (arg[i] != '%' && arg[i])
        i++;
    write(1, arg, i);
    printf("i: %d\n", i);
    return (i);
}

a_list ft_strchr_multiple(const char *arg, int i, char *target, a_list flag_list)
{
    int j;
    char *ans;
    
    j = 0;
    while (target[j] != 0)
    {
        ans = ft_strchr(arg, target[j]);
        if (ans != NULL)
            flag_list.flag = 1;
        j++;
    }
    return (flag_list);
}

a_list ft_printf_per(const char *arg, int i, a_list flag_list)
{
    flag_list = ft_strchr_multiple(arg, i, "-0", flag_list);
    return (flag_list);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char const	*ptr_s;
	int					i;

	ptr_s = (unsigned char const *)s;
	i = 0;
	while (ptr_s[i] != '\0')
	{
		if (ptr_s[i] == (unsigned char)c)
		{
			return (char *)(s + i);
		}
		i++;
	}
	if (ptr_s[i] == '\0' && ptr_s[i] == (unsigned char)c)
	{
		return (char *)(s + i);
	}
	return (NULL);
}

a_list init_list(a_list flag_list)
{
    flag_list.flag = -1;
    return (flag_list);
}

int ft_printf(const char *arg, ...)
{
    va_list ap;
    int i;
    a_list flag_list;
    
    va_start(ap, arg);
    flag_list = init_list(flag_list);
    i = 0;
    if (arg == NULL)
        i = -1;
    while (i >= 0 && *arg)
    {
        if (arg[i] != '%')
            i = ft_printf_str(arg, i);
        else
        {
            flag_list = ft_printf_per(arg, i, flag_list);
        }
    }
    printf("list: %d\n", flag_list.flag);
    va_end(ap);
    
    return (i);
}

// int ft_printf(const char *arg, ...)
// {
//     va_list ap;
//     int i;
//     int j;
//     int digit;
//     char tmp;
//     char *tmp2;
    
//     va_start(ap, arg);
//     i = 0;
//     while (arg[i])
//     {
//         if (arg[i] == '%')
//         {
//             i++;
//             if (arg[i] == 'c')
//             {
//                 tmp = (char)va_arg(ap, int);
//                 write(1, &tmp, 1);
//                 i++;
//             }
//             else if (arg[i] == 's')
//             {
//                 tmp2 = va_arg(ap, char*);
//                 ft_putstr_fd(tmp2, 1);
//                 i++;
//             }
//             else if (arg[i] == '%')
//             {
//                 while (arg[i] == '%')
//                 {
//                     write(1, "%", 1);
//                     i++;
//                 }
//             }
//             else if (ft_isdigit(arg[i]))
//             {
//                 digit = 0;
//                 while (ft_isdigit(arg[i]))
//                 {
//                     digit = ft_atoi(&arg[i]);
//                     j = 1;
//                     while (j < digit)
//                     {
//                         write(1, " ", 1);
//                         j++;
//                     }
//                     while ((digit / 10) > 0)
//                     {
//                         digit = digit / 10;
//                         i++;
//                     }
//                     i++;
//                 }
//                 if (arg[i] == 'c')
//                 {
//                     tmp = (char)va_arg(ap, int);
//                     write(1, &tmp, 1);
//                     i++;
//                 }
//                 else if (arg[i] == 's')
//                 {
                    
//                     tmp2 = va_arg(ap, char*);
//                     ft_putstr_fd(tmp2, 1);
//                     i++;
//                 }
//             }
//         }
//         else
//         {
//             write(1, &arg[i], 1);
//             i++;
//         }
//     }
//     va_end(ap);
    
//     return (0);
// }