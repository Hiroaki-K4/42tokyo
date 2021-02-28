/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:39:32 by hkubo             #+#    #+#             */
/*   Updated: 2021/02/28 14:40:59 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

size_t		ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int ft_printf(const char *arg, ...)
{
    va_list ap;
    int i;
    char tmp;
    char *tmp2;
    
    va_start(ap, arg);
    i = 0;
    while (arg[i])
    {
        if (arg[i] == '%')
        {
            i++;
            if (arg[i] == 'c')
            {
                tmp = (char)va_arg(ap, int);
                write(1, &tmp, 1);
                // write(1, "\n", 1);
                // printf("%c\n", (char)tmp);
                // write(1, &arg[i], 1);
            }
            else if (arg[i] == 's')
            {
                tmp2 = va_arg(ap, char*);
                ft_putstr_fd(tmp2, 1);
            }
            i++;
        }
        else
        {
            write(1, &arg[i], 1);
            i++;
        }
    }
    va_end(ap);
    
    return (0);
}

int main(void)
{
    char samp1 = 'b';
    char *samp2 = "ccc";
    
    printf("printf: %c\n", 'a');
    printf("printf: %c\n", samp1);
    printf("printf: %s\n", "ccc");
    printf("printf: %s\n", samp2);
    ft_printf("ft_printf: %c\n", 'a');
    ft_printf("ft_printf: %c\n", samp1);
    ft_printf("ft_printf: %s\n", "ccc");
    ft_printf("ft_printf: %s\n", samp2);
    return (0);
}