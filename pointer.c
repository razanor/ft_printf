/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 13:42:44 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/03 13:43:00 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int ft_zero(uintmax_t i, t_flags *f, int len)
{
	char *str;

	ft_putstr("0x");
	ft_put_specific_char('0', f->width - len - 2);
	ft_putstr(str = ft_itoa_unsigned(i, 16));
	ft_strdel(&str);
	return (f->width);
}

static	char *ft_precision(uintmax_t i, t_flags *f)
{
	char *str;
	char *num;
	int len;
	int b;
	int a;

	len = 0;
	b = 0;
	num = ft_itoa_unsigned(i, 16);
	f->precision > ft_base_len(i, 16) ? (str = ft_strnew(f->precision)) :
		(str = ft_strnew(ft_base_len(i, 16)));
	if (f->precision && f->precision > ft_base_len(i, 16))
	{
		a = f->precision - ft_base_len(i, 16);
		while (a--)
			str[len++] = '0';
		a = 0;
		while (num[a])
			str[len++] = num[a++];
		ft_strdel(&num);
		return (str);	
	}
	while (num[b])
		str[len++] = num[b++];
	ft_strdel(&num);
	return (str);
}

static int ft_width(uintmax_t i, int len, char **str, t_flags *f)
{
	if (f->minus)
	{
		ft_putstr("0x");
		write (1, *str, len);
		ft_put_specific_char(' ', f->width - len - 2);
	}
	else if (f->zero && !f->precision && !f->zero_precision)
	{
		ft_strdel(&(*str));
		return (ft_zero(i, f, len));
	}
	else if (f->zero_precision && i == 0)
	{
		ft_put_specific_char(' ', f->width - 2);
		ft_putstr("0x");
	}
	else
	{
		ft_put_specific_char(' ', f->width - len - 2);
		ft_putstr("0x");
		write (1, *str, len);
	}
	ft_strdel(&(*str));
	return (f->width);
}

static 	int ft_collect_for_p(uintmax_t i, t_flags *f)
{
	char *str;
	int	 len;

	str = ft_precision(i, f);
	len = ft_strlen(str);
	if (f->width && f->width > len + 2)
		return (ft_width(i, len, &str, f));
	if (f->zero_precision && i == 0)
	{
		ft_strdel(&str);
		ft_putstr("0x");
		return (2);
	}
	ft_putstr("0x");
	write (1, str, len);
	ft_strdel(&str);
	return (len + 2);
}

int ft_pointer(va_list lst, t_flags *f)
{
	uintmax_t i;

	i = va_arg(lst, uintmax_t);
	return (ft_collect_for_p(i, f));
}