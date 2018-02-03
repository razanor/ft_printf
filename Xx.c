/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ndecimal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:09:42 by nrepak            #+#    #+#             */
/*   Updated: 2018/01/24 17:10:01 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_zero(int len, uintmax_t i, t_flags *f, char c)
{
	int flag;
	char *str;

	(c == 'X') ? (ft_upper(str = ft_itoa_unsigned(i, 16))) : (str = ft_itoa_unsigned(i, 16));
	(f->slash && i) ? (flag = 2) : (flag = 0);
	if (flag)
		c == 'X' ? (ft_putstr("0X")) : (ft_putstr("0x"));
	ft_put_specific_char('0', f->width - len);
	ft_putstr(str);
	return (f->width); 
}

static char *ft_precision(uintmax_t i, char *str, t_flags *f, char c)
{
	int len;
	int a;
	int flag;
	char *num;

	len = 0;
	(c == 'X') ? (ft_upper(num = ft_itoa_unsigned(i, 16))) : (num = ft_itoa_unsigned(i, 16));
	(f->slash && i) ? (flag = 2) : (flag = 0);
	a = f->precision - ft_base_len(i, 16);
	if (flag)
	{
		str[len++] = '0';
		c == 'X' ? (str[len++] = 'X') : (str[len++] = 'x');
	}
	while (a--)
		str[len++] = '0';
	while (*num)
		str[len++] = *num++;
	return (str);
}

static char *ft_precision_slash(uintmax_t i, t_flags *f, char c)
{
	char *str;
	char *num;
	int  len;
	int  flag;

	len = 0;
	(c == 'X') ? (ft_upper(num = ft_itoa_unsigned(i, 16))) : (num = ft_itoa_unsigned(i, 16));
	(f->slash && i) ? (flag = 2) : (flag = 0);
	f->precision > ft_base_len(i, 16) ? (str = ft_strnew(f->precision + flag)) :
		(str = ft_strnew(ft_base_len(i, 16) + flag));
	if (f->precision && f->precision > ft_base_len(i, 16))
		return (ft_precision(i, str, f, c));
	if (flag)
	{
		str[len++] = '0';
		c == 'X' ? (str[len++] = 'X') : (str[len++] = 'x');
	}
	while (*num)
		str[len++] = *num++;
	return (str);
}

static int ft_collect_for_Xx(uintmax_t i, t_flags *f, char c)
{
	char *str;
	int  len;

	str = ft_precision_slash(i, f, c);
	len = ft_strlen(str);
	if (f->width && f->width > len)
	{
		if (f->minus)
		{
			ft_putstr(str);
			ft_put_specific_char(' ', f->width - len);
		}
		else if (f->zero && !f->precision)
			return (ft_zero(len, i, f, c));
		else
		{
			ft_put_specific_char(' ', f->width - len);
			ft_putstr(str);
		}
		free(str);
		return (f->width);
	}
	ft_putstr(str);
	free(str);
	return (len);
}

int	ft_Xx(va_list lst, char c, t_flags *f)
{
	uintmax_t i;
	int a;

	a = 0;
	i = va_arg(lst, uintmax_t);
	return (ft_collect_for_Xx((unsigned int)i, f, c));
}