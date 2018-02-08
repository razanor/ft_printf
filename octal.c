/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Oo.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:55:33 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/08 15:14:30 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_precision(uintmax_t i, char *str, char **num, t_flags *f)
{
	int		a;
	int		len;

	len = 0;
	a = f->precision - ft_base_len(i, 8);
	while (a--)
		str[len++] = '0';
	a = 0;
	while ((*num)[a])
		str[len++] = (*num)[a++];
	ft_strdel(&(*num));
	return (str);
}

static char		*ft_precision_slash(uintmax_t i, t_flags *f)
{
	char	*str;
	char	*num;
	int		len;
	int		flag;
	int		a;

	len = 0;
	num = ft_itoa_unsigned(i, 8);
	flag = (f->slash && i && f->precision < ft_base_len(i, 8)) ? 1 : 0;
	f->precision > ft_base_len(i, 8) ? (str = ft_strnew(f->precision)) :
		(str = ft_strnew(ft_base_len(i, 8) + flag));
	if (f->precision && f->precision > ft_base_len(i, 8))
		return (ft_precision(i, str, &num, f));
	(flag == 1) ? (str[len++] = '0') : 1;
	a = 0;
	while (num[a])
		str[len++] = num[a++];
	ft_strdel(&num);
	return (str);
}

static int		ft_width(intmax_t i, int len, char **str, t_flags *f)
{
	if (f->minus)
	{
		write(1, *str, len);
		ft_put_specific_char(' ', f->width - len);
	}
	else if (f->zero && !f->precision && !f->zero_precision)
	{
		ft_strdel(&(*str));
		return (ft_zero_octal(i, f));
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

static int		ft_collect_for_octal(uintmax_t i, t_flags *f)
{
	char	*str;
	int		len;

	str = ft_precision_slash(i, f);
	len = ft_strlen(str);
	if (f->width && f->width > len)
		return (ft_width(i, len, &str, f));
	if (f->zero_precision && i == 0 && !f->slash)
	{
		ft_strdel(&str);
		return (0);
	}
	write(1, str, len);
	ft_strdel(&str);
	return (len);
}

int				ft_octal(va_list lst, char c, t_flags *f)
{
	uintmax_t i;

	i = va_arg(lst, uintmax_t);
	if (c == 'o')
	{
		i = (CAST) ? (ft_cast_to_unsigned(i, f)) : (unsigned int)i;
		return (ft_collect_for_octal(i, f));
	}
	if (c == 'O')
		return (ft_collect_for_octal(i, f));
	return (0);
}
