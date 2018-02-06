/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 20:15:51 by nrepak            #+#    #+#             */
/*   Updated: 2018/01/28 20:15:53 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_collect_for_S(wchar_t *a, t_flags *f)
{
	if (f->width && f->width > ft_wstrlen(a))
	{
		if (f->minus)
		{
			ft_putwstr(a);
			ft_put_specific_char(' ', f->width - ft_wstrlen(a));
		}
		else
		{
			ft_put_specific_char(' ', f->width - ft_wstrlen(a));
			ft_putwstr(a);
		}
		return (f->width);
	}
	return (ft_putwstr(a));
}

static char *ft_precision(char *s, t_flags *f)
{
	char *str;

	if (f->precision && f->precision < (int)ft_strlen(s))
		str = ft_strsub(s, 0, f->precision);
	else
		str = ft_strdup(s);
	return (str);
}

static int	ft_collect_for_s(char *s, t_flags *f)
{
	char *str;
	int	 len;

	str = ft_precision(s, f);
	len = ft_strlen(str);
	if (f->width && f->width > len)
	{
		if (f->minus)
		{
			write (1, str, len);
			ft_put_specific_char(' ', f->width - len);
		}
		else if (f->zero)
		{
			ft_put_specific_char('0', f->width - len);
			write (1, str, len);
		}
		else if (f->zero_precision)
			ft_put_specific_char(' ', f->width);
		else 
		{
			ft_put_specific_char(' ', f->width - len);
			write (1, str, len);
		}
		ft_strdel(&str);
		return (f->width);
	}
	write (1, str, len);
	ft_strdel(&str);
	return (len);
}

int	ft_Ss(va_list lst, char c, t_flags *f)
{
	char *s;
	wchar_t *a;

	if (c == 's')
	{
		if (ft_if_cast_flags(f))
			return (ft_collect_for_S((va_arg(lst, wchar_t*)), f));
		if (!(s = va_arg(lst, char*)))
		{
			ft_putstr("(null)");
			return (6);
		}
		return (ft_collect_for_s(s, f));
	}
	if (c == 'S')
	{
		if (!(a = va_arg(lst, wchar_t*)))
		{
			ft_putstr("(null)");
			return (6);
		}
		return (ft_collect_for_S(a, f));
	}
	return (1);
}