/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ndecimal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:09:42 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/07 23:32:00 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_precision(uintmax_t i, char *str, t_flags *f, char c)
{
	int		len;
	int		a;
	int		flag;
	char	*num;

	len = 0;
	num = ft_upper_lower_string(i, c);
	flag = (f->slash && i) ? 2 : 0;
	a = f->precision - ft_base_len(i, 16);
	if (flag)
	{
		str[len++] = '0';
		str[len++] = (c == 'X') ? 'X' : 'x';
	}
	while (a--)
		str[len++] = '0';
	a = 0;
	while (num[a])
		str[len++] = num[a++];
	ft_strdel(&num);
	return (str);
}

static char		*ft_precision_slash(uintmax_t i, t_flags *f, char c)
{
	char	*str;
	char	*num;
	int		len;
	int		flag;
	int		a;

	len = 0;
	a = 0;
	num = ft_upper_lower_string(i, c);
	flag = (f->slash && i) ? 2 : 0;
	str = (f->precision > ft_base_len(i, 16)) ? ft_strnew(f->precision + flag) :
		ft_strnew(ft_base_len(i, 16) + flag);
	if (f->precision && f->precision > ft_base_len(i, 16))
		return (ft_precision(i, str, f, c));
	if (flag)
	{
		str[len++] = '0';
		str[len++] = (c == 'X') ? 'X' : 'x';
	}
	while (num[a])
		str[len++] = num[a++];
	ft_strdel(&num);
	return (str);
}

static int		ft_width(intmax_t i, char **str, t_flags *f, char c)
{
	int len;

	if ((len = ft_strlen(*str)) && f->minus)
	{
		write(1, *str, len);
		ft_put_specific_char(' ', f->width - len);
	}
	else if (f->zero && !f->precision && !f->zero_precision)
	{
		ft_strdel(&(*str));
		return (ft_zero_hexadecimal(len, i, f, c));
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

static int		ft_collect_for_hexadecimal(uintmax_t i, t_flags *f, char c)
{
	char	*str;
	int		len;

	str = ft_precision_slash(i, f, c);
	len = ft_strlen(str);
	if (f->width && f->width > len)
		return (ft_width(i, &str, f, c));
	if (f->zero_precision && i == 0)
	{
		ft_strdel(&str);
		return (0);
	}
	write(1, str, len);
	ft_strdel(&str);
	return (len);
}

int				ft_hexadecimal(va_list lst, char c, t_flags *f)
{
	uintmax_t i;

	i = va_arg(lst, uintmax_t);
	i = (CAST) ? (ft_cast_to_unsigned(i, f)) : (unsigned int)i;
	return (ft_collect_for_hexadecimal(i, f, c));
}
