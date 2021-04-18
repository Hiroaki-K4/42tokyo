/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:39:32 by hkubo             #+#    #+#             */
/*   Updated: 2021/04/04 10:55:18 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
// # include <stdint.h>

typedef	struct
{
	int flag[2];
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

int		ft_printf_str(const char *arg, int *i)
{
	int	len;

	len = 0;
	while (arg[*i] != '%' && arg[*i])
	{
		write(1, &arg[*i], 1);
		(*i)++;
		len++;
	}
	return (len);
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

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~print string~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int	field_flag_str(char *str, t_plist flag_list, int len)
{
	int i;

	if (flag_list.precision != -1 && flag_list.precision < (int)ft_strlen(str))
	{
		write(1, str, flag_list.precision);
		i = flag_list.precision;
		while (flag_list.field - i > 0)
		{
			write(1, " ", 1);
			i++;
		}
		len = i;
	}
	else
	{
		write(1, str, ft_strlen(str));
		i = 0;
		while ((flag_list.field - (int)ft_strlen(str) - i) > 0)
		{
			write(1, " ", 1);
			i++;
		}
		len = (int)ft_strlen(str) + i;
	}
	return (len);
}

int	no_precision(char *str, t_plist flag_list, int i, int len)
{
	if (flag_list.flag[1] == 1)
	{
		i = 0;
		while ((flag_list.field - (int)ft_strlen(str) - i) > 0)
		{
			write(1, "0", 1);
			i++;
		}
		write(1, str, ft_strlen(str));
		len = (int)ft_strlen(str) + i;
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
		len = (int)ft_strlen(str) + i;
	}
	return (len);
}

int	field_no_flag_str(char *str, t_plist flag_list, int i, int len)
{
	if (flag_list.precision != -1 && flag_list.precision < (int)ft_strlen(str))
	{
		i = flag_list.precision;
		while ((flag_list.field - i) > 0)
		{
			write(1, " ", 1);
			i++;
		}
		write(1, str, flag_list.precision);
		len = i;
	}
	else
		len = no_precision(str, flag_list, i, len);
	return (len);
}

int	no_field_str(char *str, t_plist flag_list)
{
	int len;

	len = 0;
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
	return (len);
}

int	print_string(va_list *ap, t_plist flag_list)
{
	int		len;
	char	*str;

	len = 0;
	str = va_arg(*ap, char*);
	if (str == NULL)
		str = "(null)";
	if (flag_list.field != -1)
	{
		if (flag_list.flag[0] == 1)
			len = field_flag_str(str, flag_list, 0);
		else
			len = field_no_flag_str(str, flag_list, 0, 0);
	}
	else
		len = no_field_str(str, flag_list);
	return (len);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~print string~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~print int~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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

int	pre_arg_zero(t_plist flag_list)
{
	int i;

	i = 0;
	if (flag_list.field != -1)
	{
		while (flag_list.field - i > 0)
		{
			write(1, " ", 1);
			i++;
		}
	}
	return (i);
}

char	*field_precision_sub(int num, char *str, t_plist flag_list, int i)
{
	int		j;
	char	*tmp;

	if (num < 0)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (flag_list.precision + 2))))
			return (NULL);
		tmp[0] = '-';
		i = 1;
		while ((flag_list.precision + 2 - (int)ft_strlen(str) - i) > 0)
			tmp[i++] = '0';
		j = 1;
	}
	else
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (flag_list.precision + 1))))
			return (NULL);
		while ((flag_list.precision - (int)ft_strlen(str) - i) > 0)
			tmp[i++] = '0';
		j = 0;
	}
	while ((ft_strlen(str) - j) > 0)
		tmp[i++] = str[j++];
	tmp[i] = '\0';
	return (tmp);
}

int	field_precision(int num, char *str, t_plist flag_list, int i)
{
	char	*tmp;

	if (!(tmp = field_precision_sub(num, str, flag_list, 0)))
		return (-1);
	if (flag_list.flag[0] == 1)
	{
		write(1, tmp, ft_strlen(tmp));
		i = 0;
		while ((flag_list.field - (int)ft_strlen(tmp) - (i++)) > 0)
			write(1, " ", 1);
	}
	else
	{
		i = 0;
		while ((flag_list.field - (int)ft_strlen(tmp) - (i++)) > 0)
			write(1, " ", 1);
		write(1, tmp, ft_strlen(tmp));
		if (flag_list.precision > flag_list.field)
		{
			free(tmp);
			return (flag_list.precision);
		}
	}
	free(tmp);
	return (flag_list.field);
}

int		field_no_precision_sub(long num, char *str, t_plist flag_list, int i)
{
	char *tmp;

	if (num < 0 && flag_list.flag[0] != 1 && flag_list.flag[1] == 1)
	{
		write(1, "-", 1);
		while ((flag_list.field - (int)ft_strlen(str) - (i++)) > 0)
			write(1, "0", 1);
		num *= -1;
		if (!(tmp = ft_itoa(num)))
			return (-1);
		write(1, tmp, ft_strlen(tmp));
		free(tmp);
	}
	else
	{
		while ((flag_list.field - (int)ft_strlen(str) - (i++)) > 0)
		{
			if (flag_list.flag[1] == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
		write(1, str, ft_strlen(str));
	}
	return (0);
}

int	field_no_precision(int num, char *str, t_plist flag_list, int i)
{
	if (flag_list.flag[0] == 1)
	{
		write(1, str, ft_strlen(str));
		while ((flag_list.field - (int)ft_strlen(str) - (i++)) > 0)
			write(1, " ", 1);
	}
	else
	{
		if (field_no_precision_sub(num, str, flag_list, i) == -1)
			return (-1);
	}
	return (flag_list.field);
}

int		no_field_int_sub(t_plist flag_list, int num, int digit)
{
	int		len;
	char	*tmp;

	if (!(tmp = ft_itoa(num * (-1))))
		return (-1);
	write(1, "-", 1);
	len = flag_list.precision + 1;
	while (flag_list.precision - (digit++) > 0)
		write(1, "0", 1);
	write(1, tmp, ft_strlen(tmp));
	free(tmp);
	return (len);
}

int	no_field_int(int num, char *str, t_plist flag_list, int len)
{
	int		digit;

	digit = ft_strlen(str);
	if (num < 0)
		digit = ft_strlen(str) - 1;
	if (flag_list.precision > digit)
	{
		len = flag_list.precision;
		if (num < 0)
			len = no_field_int_sub(flag_list, num, digit);
		else
		{
			while (flag_list.precision - (digit++) > 0)
				write(1, "0", 1);
			write(1, str, ft_strlen(str));
		}
	}
	else
	{
		write(1, str, ft_strlen(str));
		len = ft_strlen(str);
	}
	return (len);
}

int		print_int_len(t_plist flag_list, char *str_num, int keta, int num)
{
	int len;

	if (flag_list.field > (int)ft_strlen(str_num))
	{
		if (flag_list.precision > keta)
			len = field_precision(num, str_num, flag_list, 0);
		else
			len = field_no_precision(num, str_num, flag_list, 0);
	}
	else
		len = no_field_int(num, str_num, flag_list, 0);
	return (len);
}

int	print_int(va_list *ap, t_plist flag_list)
{
	int		num;
	int		len;
	int		keta;
	char	*str_num;

	len = 0;
	num = va_arg(*ap, int);
	if (!(str_num = ft_itoa(num)))
		return (-1);
	keta = ft_strlen(str_num);
	if (flag_list.flag[1] == 1 && flag_list.precision != -1)
		flag_list.flag[1] = 0;
	if (num < 0)
		keta--;
	if (flag_list.precision == 0 && num == 0)
	{
		free(str_num);
		return (pre_arg_zero(flag_list));
	}
	len = print_int_len(flag_list, str_num, keta, num);
	free(str_num);
	return (len);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~print int~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~print hex~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

char			*ft_itoa_hex(unsigned int n, char *arg)
{
	int				len;
	unsigned int	i;
	unsigned int	j;
	char			*ans;

	len = get_len(n);
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

int	print_hex(va_list *ap, t_plist flag_list, int len)
{
	unsigned	int	num;
	char			*str_num;

	num = va_arg(*ap, unsigned int);
	if (flag_list.format == 6)
		str_num = ft_itoa_hex(num, "0123456789abcdef");
	else
		str_num = ft_itoa_hex(num, "0123456789ABCDEF");
	if (!(str_num))
		return (-1);
	if ((int)num < 0)
		num *= -1;
	if (flag_list.flag[1] == 1 && flag_list.precision != -1)
		flag_list.flag[1] = 0;
	if (flag_list.precision == 0 && num == 0)
	{
		free(str_num);
		return (pre_arg_zero(flag_list));
	}
	len = get_hex_len(flag_list, num, str_num);
	free(str_num);
	return (len);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~print hex~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int		output_per(va_list *ap, t_plist flag_list)
{
	int	i;

	i = 0;
	if (flag_list.format == 0)
		i = print_string(ap, flag_list);
	else if (flag_list.format == 1)
		i = print_int(ap, flag_list);
	else if (flag_list.format == 2)
		i = print_hex(ap, flag_list, 0);
	return (i);
}

int		str_to_num_field(const char *arg, int *i, va_list *ap, t_plist *f_list)
{
	int	num;
	int	j;

	if (*arg == '*')
	{
		num = va_arg(*ap, int);
		if (num < 0)
		{
			f_list->flag[0] = 1;
			num *= -1;
		}
		(*i)++;
		return (num);
	}
	j = ft_atoi(arg);
	if (j > 0)
	{
		num = j;
		j = 0;
		while (ft_isdigit(arg[j++]))
			(*i)++;
	}
	else
		num = -1;
	return (num);
}

int		str_to_num_pre(const char *arg, int *i, va_list *ap, int k)
{
	int	num;

	if (*arg == '*')
	{
		num = va_arg(*ap, int);
		if (num < 0)
			num = -1;
		(*i)++;
		return (num);
	}
	if (ft_isdigit(arg[0]) == 0)
		return (0);
	num = ft_atoi(arg);
	if (num >= 0)
	{
		while (ft_isdigit(arg[k++]))
			(*i)++;
	}
	else
		num = -1;
	return (num);
}

t_plist	init_plist(void)
{
	t_plist	flag_list;

	flag_list.field = -1;
	flag_list.precision = -1;
	flag_list.format = -1;
	return (flag_list);
}

int		ft_printf_per(const char *arg, int *i, va_list *ap)
{
	int		k;
	t_plist	flag_list;

	(*i)++;
	flag_list = init_plist();
	flag_list.field = str_to_num_field(&arg[*i], i, ap, &flag_list);
	if (arg[*i] == '.')
	{
		(*i)++;
		flag_list.precision = str_to_num_pre(&arg[*i], i, ap, 0);
	}
	flag_list.format = ft_strchr_place("sdx", arg[*i], i);
	k = output_per(ap, flag_list);
	return (k);
}

int		ft_printf(const char *arg, ...)
{
	va_list	ap;
	int		i;
	int		j;
	int		print_len;

	va_start(ap, arg);
	i = 0;
	if (arg == NULL)
		i = -1;
	print_len = 0;
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
