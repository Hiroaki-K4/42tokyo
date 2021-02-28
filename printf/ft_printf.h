/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:52:50 by hkubo             #+#    #+#             */
/*   Updated: 2021/02/28 14:53:54 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

size_t		ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
int ft_printf(const char *arg, ...);