/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:29:42 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/08 20:14:42 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_check_which(char c, va_list lst, t_flags *f)
{
	if (ft_conversions(c) == 1)
		return (ft_percentage(f));
	if (ft_conversions(c) == 2)
		return (ft_decimal(lst, c, f));
	if (ft_conversions(c) == 3)
		return (ft_character(lst, c, f));
	if (ft_conversions(c) == 4)
		return (ft_string(lst, c, f));
	if (ft_conversions(c) == 5)
		return (ft_hexadecimal(lst, c, f));
	if (ft_conversions(c) == 6)
		return (ft_octal(lst, c, f));
	if (ft_conversions(c) == 7)
		return (ft_unsigned_decimal(lst, c, f));
	if (ft_conversions(c) == 8)
		return (ft_pointer(lst, f));
	return (0);
}

static	int		ft_check_flags(const char **str, va_list lst)
{
	t_flags		f;
	int			n_width;
	int			n_precision;

	f.width = 0;
	f.precision = 0;
	n_width = ft_check_width(*str);
	n_precision = ft_check_precision(*str);
	n_width ? (f.width = n_width) : 1;
	n_precision ? (f.precision = n_precision) : 1;
	ft_zero_to_all(&f);
	ft_find_cast_flags(*str, &f);
	ft_zero_precision(*str, &f);
	while (*str && ft_conversions(**str) == 0)
	{
		ft_collect_flags(**str, &f, &str, n_width);
		(*str)++;
	}
	return (ft_check_which(**str, lst, &f));
}

static void		ft_gather_flags(const char **str, int *len, int *i, va_list lst)
{
	if ((ft_is_conversions(*str)))
	{
		(*len) = (*len) + ft_check_flags(str, lst);
		(*str)++;
	}
	else
		while (ft_is_flags(**str))
			(*str)++;
	(*i)--;
}

static int		ft_core(const char *str, va_list lst)
{
	int			i;
	int			len;

	i = 0;
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_gather_flags(&str, &len, &i, lst);
		}
		else
		{
			ft_putchar(*str);
			str++;
		}
		i++;
	}
	return (len + i);
}

int				ft_printf(const char *str, ...)
{
	va_list		lst;
	int			i;

	va_start(lst, str);
	i = ft_core(str, lst);
	va_end(lst);
	return (i);
}
