/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:08:23 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/08 15:40:27 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*ft_precision(uintmax_t i, char *str, char **num, t_flags *f)
{
	int a;
	int len;

	len = 0;
	a = f->precision - ft_base_len(i, 10);
	while (a--)
		str[len++] = '0';
	a = 0;
	while ((*num)[a])
		str[len++] = (*num)[a++];
	ft_strdel(&(*num));
	return (str);
}

static	char	*ft_precision_string(uintmax_t i, t_flags *f)
{
	char	*str;
	char	*num;
	int		len;
	int		b;

	len = 0;
	b = 0;
	num = ft_itoa_unsigned(i, 10);
	f->precision > ft_base_len(i, 10) ? (str = ft_strnew(f->precision)) :
		(str = ft_strnew(ft_base_len(i, 10)));
	if (f->precision && f->precision > ft_base_len(i, 10))
		return (ft_precision(i, str, &num, f));
	while (num[b])
		str[len++] = num[b++];
	ft_strdel(&num);
	return (str);
}

static int		ft_width(uintmax_t i, int len, char **str, t_flags *f)
{
	if (f->minus)
	{
		write(1, *str, len);
		ft_put_specific_char(' ', f->width - len);
	}
	else if (f->zero && !f->precision && !f->zero_precision)
	{
		ft_strdel(&(*str));
		return (ft_zero_unsigned_decimal(i, f, len));
	}
	else if (f->zero_precision && i == 0)
	{
		ft_strdel(&(*str));
		ft_put_specific_char(' ', f->width - len + 1);
		return (f->width);
	}
	else
	{
		ft_put_specific_char(' ', f->width - len);
		write(1, *str, len);
	}
	ft_strdel(&(*str));
	return (f->width);
}

static int		ft_collect_for_unsigned_decimal(uintmax_t i, t_flags *f)
{
	char	*str;
	int		len;

	str = ft_precision_string(i, f);
	len = ft_strlen(str);
	if (f->width && f->width > len)
		return (ft_width(i, len, &str, f));
	if (f->zero_precision && i == 0)
	{
		ft_strdel(&str);
		return (0);
	}
	write(1, str, len);
	ft_strdel(&str);
	return (len);
}

int				ft_unsigned_decimal(va_list lst, char c, t_flags *f)
{
	uintmax_t i;

	i = va_arg(lst, uintmax_t);
	if (c == 'u')
	{
		i = (CAST) ? (ft_cast_to_unsigned(i, f)) : (unsigned int)i;
		return (ft_collect_for_unsigned_decimal(i, f));
	}
	if (c == 'U')
		return (ft_collect_for_unsigned_decimal(i, f));
	return (0);
}
