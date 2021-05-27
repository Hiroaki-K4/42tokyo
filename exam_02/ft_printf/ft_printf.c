/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:39:32 by hkubo             #+#    #+#             */
/*   Updated: 2021/05/27 09:21:34 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
// # include <stdint.h>

typedef	struct
{
	int field;
	int precision;
	int format;
}		t_plist;

size_t		ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

static	int		digit_size(int number)
{
	int		count;

	count = 0;
	if (number <= 0)
		count++;
	while (number != 0)
	{
		number = number / 10;
		count++;
	}
	return (count);
}

char	*ft_strdup(const char *s)
{
	char	*new_ptr;
	int		i;
	int		size;

	size = 0;
	while (s[size] != '\0')
		size++;
	if (!(new_ptr = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new_ptr[i] = s[i];
		i++;
	}
	new_ptr[i] = '\0';
	return (new_ptr);
}

char			*ft_itoa(int n)
{
	int		len;
	char	flag;
	char	*ans;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = digit_size(n);
	if (!(ans = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	flag = '+';
	if (n < 0)
	{
		n = n * (-1);
		flag = '-';
	}
	ans[len] = '\0';
	len--;
	while (len >= 0)
	{
		ans[len--] = '0' + (n % 10);
		n = n / 10;
	}
	if (flag == '-')
		ans[0] = '-';
	return (ans);
}

int		ft_strchr_place(const char *str, int c, int *i)
{
	int	j;

	j = 0;
	while (j < (int)ft_strlen(str))
	{
		if (str[j] == c)
		{
			(*i)++;
			return (j);
		}
		j++;
	}
	return (-1);
}

char			*ft_itoa_hex(unsigned int n, char *arg)
{
	int				len;
	unsigned int	i;
	unsigned int	j;
	char			*ans;

	i = n / 16;
	if (i != 0)
	{
		len = 2;
		while (i > 16)
		{
			len++;
			i = i / 16;
		}
	}
	else
		len = 1;
	if (!(ans = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ans[len] = '\0';
	i = n;
	len--;
	if (i == 0)
	{
		ans[0] = '0';
		return (ans);
	}
	while (i > 0)
	{
		j = i % 16;
		ans[len] = arg[j];
		i = i / 16;
		len--;
	}
	return (ans);
}

int		ft_atoi(const char *nptr)
{
	int		i;
	int		flag;
	int		ans;

	flag = 1;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n' ||
			nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			flag = -1;
		i++;
	}
	ans = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		ans = (ans * 10) + (nptr[i] - '0');
		i++;
	}
	ans = ans * flag;
	return (ans);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// int	field_precision(t_plist flag_list, char *str_num, int num, int i)
// {
// 	int		j;
// 	char	*tmp;

// 	if (num < 0)
// 	{
// 		if (!(tmp = (char *)malloc(sizeof(char) * (flag_list.precision + 2))))
// 			return (-1);
// 		tmp[0] = '-';
// 		i = 1;
// 		while ((flag_list.precision + 2 - (int)ft_strlen(str_num) - i) > 0)
// 			tmp[i++] = '0';
// 		j = 1;
// 	}
// 	else
// 	{
// 		if (!(tmp = (char *)malloc(sizeof(char) * (flag_list.precision + 1))))
// 			return (-1);
// 		while ((flag_list.precision - (int)ft_strlen(str_num) - i) > 0)
// 			tmp[i++] = '0';
// 		j = 0;
// 	}
// 	while ((ft_strlen(str_num) - j) > 0)
// 		tmp[i++] = str_num[j++];
// 	tmp[i] = '\0';
// 	i = 0;
// 	while ((flag_list.field - (int)ft_strlen(tmp) - (i++)) > 0)
// 		write(1, " ", 1);
// 	write(1, tmp, ft_strlen(tmp));
// 	free(tmp);
// 	if (flag_list.precision > flag_list.field)
// 		return (flag_list.precision);
// 	return (flag_list.field);
// }

int field_precision(t_plist flag_list, char *str_num, int num, int i)
{
	int j;
	char *tmp;

	if (num < 0)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (flag_list.precision + 2))))
			return (-1);
		tmp[0] = '-';
		while ((flag_list.precision + 2 - (int)ft_strlen(str_num) - i) > 0)
			tmp[i++] = '0';
		j = 1;
	}
	else
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (flag_list.precision + 1))))
			return (-1);
		write((flag_list.precision - (int)ft_strlen(str_num) - i) > 0)
			tmp[i++] = '0';
		j = 0;
	}
	while ((ft_strlen(str_num) - j) > 0)
		tmp[i++] = str_num[j++];
	tmp[i] = '\0';
	i = 0;
	while ((flag_list.field - (int)ft_strlen(tmp) - (i++)) > 0)
		write(1, " ", 1);
	write(1, tmp, ft_strlen(tmp));
	free(tmp);
	if (flag_list.precision > flag_list.field)
		return (flag_list.precision);
	return (flag_list.field);
}

// int	no_field_int(t_plist flag_list, char *str_num, int num, int len)
// {
// 	int		keta;
// 	char	*tmp;
	
// 	keta = ft_strlen(str_num);
// 	if (num < 0)
// 		keta--;
// 	if (flag_list.precision > keta)
// 	{
// 		len = flag_list.precision;
// 		if (num < 0)
// 		{
// 			if (!(tmp = ft_itoa(num * (-1))))
// 				return (-1);
// 			write(1, "-", 1);
// 			while (flag_list.precision - (keta++) > 0)
// 				write(1, "0", 1);
// 			write(1, tmp, ft_strlen(tmp));
// 			free(tmp);
// 			len = flag_list.precision + 1;
// 		}
// 		else
// 		{
// 			while (flag_list.precision - (keta++) > 0)
// 				write(1, "0", 1);
// 			write(1, str_num, ft_strlen(str_num));
// 		}
// 	}
// 	else
// 	{
// 		write(1, str_num, ft_strlen(str_num));
// 		len = ft_strlen(str_num);
// 	}
// 	return (len);
// }

int no_field_int(t_plist flag_list, char *str_num, int num, int len)
{
	int keta;
	char *tmp;

	keta = ft_strlen(str_num);
	if (num < 0)
		keta--;
	if (flag_list.precision > (int)ft_strlen(str_num))
	{
		len = flag_list.precision;
		if (num < 0)
		{
			if (!(tmp = ft_itoa(num * (-1))))
				return (-1);
			write(1, "-", 1);
			while (flag_list.precision - (keta++) > 0)
				write(1, "0", 1);
			write(1, tmp, ft_strlen(tmp));
			len = flag_list.precision + 1;
		}
		else
		{
			while (flag_list.precision - (keta++) > 0)
				write(1, "0", 1);
			write(1, str_num, ft_strlen(str_num));
		}
	}
	else
	{
		write(1, str_num, ft_strlen(str_num));
		len = ft_strlen(str_num);
	}
	return (len);
}

// int print_digit(t_plist flag_list, char *str_num, int num, int keta)
// {
// 	int len;
	
// 	len = 0;
// 	if (flag_list.precision == 0 && num == 0)
// 	{
// 		while (flag_list.field - len > 0)
// 		{
// 			write(1, " ", 1);
// 			len++;
// 		}
// 	}
// 	else if (flag_list.field > (int)ft_strlen(str_num))
// 	{
// 		if (flag_list.precision > keta)
// 			len = field_precision(flag_list, str_num, num, 0);
// 		else
// 		{
// 			while ((flag_list.field - (int)ft_strlen(str_num) - (len++)) > 0)
// 				write(1, " ", 1);
// 			write(1, str_num, ft_strlen(str_num));
// 			len = flag_list.field;
// 		}
// 	}
// 	else
// 		len = no_field_int(flag_list, str_num, num, 0);
// 	free(str_num);
// 	return (len);
// }

int print_digit(t_plist flag_list, char *str_num, int num, int keta)
{
	int len;

	len = 0;
	if (flag_list.precision == 0 && num == 0)
	{
		while (len < flag_list.field)
		{
			write(1, " ", 1);
			len++;
		}
	}
	else if (flag_list.field > (int)ft_strlen(str_num))
	{
		if (flag_list.precision > keta)
			len = field_precision(flag_list, str_num, num, 0);
		else
		{
			while (flag_list.field - (int)ft_strlen(str_num) - (len++) > 0)
				write(1, " ", 1);
			write(1, str_num, ft_strlen(str_num));
		}
	}
	else
		len = no_field_int(flag_list, str_num, num, 0);
	free(str_num);
	return (len);
}

// int	print_string(va_list *ap, t_plist flag_list)
// {
// 	int		i;
// 	int		len;
// 	char	*str;

// 	len = 0;
// 	str = va_arg(*ap, char*);
// 	if (str == NULL)
// 		str = "(null)";
// 	if (flag_list.field != -1)
// 	{
// 		if (flag_list.precision != -1 && flag_list.precision < (int)ft_strlen(str))
// 		{
// 			i = flag_list.precision;
// 			while ((flag_list.field - i) > 0)
// 			{
// 				write(1, " ", 1);
// 				i++;
// 			}
// 			write(1, str, flag_list.precision);
// 			len = i;
// 		}
// 		else
// 		{
// 			i = 0;
// 			while ((flag_list.field - (int)ft_strlen(str) - i) > 0)
// 			{
// 				write(1, " ", 1);
// 				i++;
// 			}
// 			write(1, str, ft_strlen(str));
// 			len = (int)ft_strlen(str) + i;
// 		}
// 	}
// 	else
// 	{
// 		if (flag_list.precision != -1)
// 		{
// 			while (len < flag_list.precision && str[len])
// 			{
// 				write(1, &str[len], 1);
// 				len++;
// 			}
// 		}
// 		else
// 		{
// 			write(1, str, ft_strlen(str));
// 			len = ft_strlen(str);
// 		}
// 	}
// 	return (len);
// }

int print_string(va_list *ap, t_plist flag_list)
{
	int len;
	int i;
	char *str;

	len = 0;
	str = va_arg(*ap, char*);
	if (str == NULL)
		str = "(null)";
	if (flag_list.field != -1)
	{
		if (flag_list.precision != -1 && flag_list.precision < (int)ft_strlen(str))
		{
			i = flag_list.precision;
			while (flag_list.field - i > 0)
			{
				write(1, " ", 1);
				i++;
			}
			write(1, str, flag_list.precision);
			len = i;
		}
		else
		{
			i = 0;
			while ((flag_list.field - (int)ft_strlen(str) - i) > 0)
			{
				write(1, " ", 1);
				i++;
			}
			write(1, str, ft_strlen(str));
			len = ft_strlen(str) + i;
		}
	}
	else
	{
		if (flag_list.precision != -1)
		{
			while (len < flag_list.precision && str[len])
			{
				write(1, &str[len], 1);
				len++;
			}
		}
		else
		{
			write(1, str, ft_strlen(str));
			len = ft_strlen(str);
		}
	}
	return (len);
}


// int		str_to_num(const char *arg, int *i, int flag)
// {
// 	int	num;
// 	int	j;

// 	if (ft_isdigit(arg[0]) == 0 && flag == 1)
// 		return (0);
// 	num = ft_atoi(arg);
// 	if (num >= 0)
// 	{
// 		j = 0;
// 		while (ft_isdigit(arg[j++]))
// 			(*i)++;
// 	}
// 	else
// 		num = -1;
// 	return (num);
// }

int str_to_num(const char *arg, int *i, int flag)
{
	int num;
	int j;

	if (ft_isdigit(arg[0]) == 0 && flag == 1)
		return (0);
	num = ft_atoi(arg);
	if (num >= 0)
	{
		j = 0;
		while (ft_isdigit(arg[j++]))
			(*i)++;
	}
	else
		num = -1;
	return (num);
}

// int		ft_printf_per(const char *arg, int *i, va_list *ap)
// {
// 	int		len;
// 	int		num;
// 	int		keta;
// 	unsigned	int	hex_num;
// 	char	*str_num;
// 	t_plist	flag_list;

// 	(*i)++;
// 	flag_list.field = str_to_num(&arg[*i], i, 0);
// 	flag_list.precision = -1;
// 	if (arg[*i] == '.')
// 	{
// 		(*i)++;
// 		flag_list.precision = str_to_num(&arg[*i], i, 1);
// 	}
// 	flag_list.format = ft_strchr_place("sdx", arg[*i], i);
// 	if (flag_list.format == 0)
// 		len = print_string(ap, flag_list);
// 	else if (flag_list.format == 1)
// 	{
// 		num = va_arg(*ap, int);
// 		if (!(str_num = ft_itoa(num)))
// 			return (-1);
// 		keta = ft_strlen(str_num);
// 		if (num < 0)
// 			keta--;
// 		len = print_digit(flag_list, str_num, num, keta);
// 	}
// 	else if (flag_list.format == 2)
// 	{
// 		hex_num = va_arg(*ap, unsigned int);
// 		if (!(str_num = ft_itoa_hex(hex_num, "0123456789abcdef")))
// 			return (-1);
// 		len = print_digit(flag_list, str_num, hex_num, (int)ft_strlen(str_num));
// 	}
// 	return (len);
// }

int ft_printf_per(const char *arg, int *i, va_list *ap)
{
	int len;
	int num;
	int keta;
	unsigned int hex_num;
	char *str_num;
	t_plist flag_list;

	(*i)++;
	flag_list.field = str_to_num(&arg[*i], i, 0);
	flag_list.precision = -1;
	if (arg[*i] == '.')
	{
		(*i)++;
		flag_list.precision = str_to_num(&arg[*i], i, 1);
	}
	flag_list.format = ft_strchr_place("sdx", arg[*i], i);
	if (flag_list.format == 0)
		len = print_string(ap, flag_list);
	else if (flag_list.format == 1)
	{
		num = va_arg(*ap, int);
		if (!(str_num = ft_itoa(num)))
			return (-1);
		keta = ft_strlen(str_num);
		if (num < 0)
			keta--;
		len = print_digit(flag_list, str_num, num, keta);
	}
	else if (flag_list.format == 2)
	{
		hex_num = va_arg(*ap, unsigned int);
		if (!(str_num = ft_itoa_hex(hex_num, "0123456789abcdef")))
			return (-1);
		len = print_digit(flag_list, str_num, hex_num, (int)ft_strlen(str_num));
	}
	return (len);
}

// int		ft_printf_str(const char *arg, int *i)
// {
// 	int	len;

// 	len = 0;
// 	while (arg[*i] != '%' && arg[*i])
// 	{
// 		write(1, &arg[*i], 1);
// 		(*i)++;
// 		len++;
// 	}
// 	return (len);
// }

int ft_printf_str(const char *arg, int *i)
{
	int len;

	len = 0;
	while (arg[*i] && arg[*i] != '%')
	{
		write(1, &arg[*i], 1);
		(*i)++;
		len++;
	}
	return (len);
}

// int		ft_printf(const char *arg, ...)
// {
// 	va_list	ap;
// 	int		i;
// 	int		j;
// 	int		print_len;

// 	va_start(ap, arg);
// 	i = 0;
// 	if (arg == NULL)
// 		i = -1;
// 	print_len = 0;
// 	while (i >= 0 && arg[i])
// 	{
// 		if (arg[i] != '%')
// 			print_len += ft_printf_str(arg, &i);
// 		else
// 		{
// 			j = ft_printf_per(arg, &i, &ap);
// 			if (j == -1)
// 				return (-1);
// 			print_len += j;
// 		}
// 	}
// 	va_end(ap);
// 	return (print_len);
// }

int ft_printf(const char *arg, ...)
{
	int i;
	int j;
	int print_len;
	va_list ap;
	
	va_start(ap, arg);
	i = 0;
	print_len = 0;
	if (arg == NULL)
		i = -1;
	while (i >= 0 && arg[i])
	{
		if (arg[i] != '%')
			print_len += ft_printf_str(arg, &i);
		else
		{
			j = ft_printf_per(arg, &i, &ap);
			if (j == -1)
				return (-1);
			print_len += j;
		}
	}
	va_end(ap);
	return (print_len);
}