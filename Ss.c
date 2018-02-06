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

static wchar_t *ft_precision_S(wchar_t *a, t_flags *f)
{
	int size;
	int b;
	wchar_t *str;

	b = 0;
	while (b[a])
		b++;
	if (b)
		size = ft_wstrlen(a) / b;
	if (f->precision && f->precision < ft_wstrlen(a))
		str = ft_strwsub(a, 0, f->precision / size);
	else
		str = ft_strwdup(a);
	return (str);
}

static	int	ft_collect_for_S(wchar_t *a, t_flags *f)
{
	wchar_t *str;
	int len;

	str = ft_precision_S(a, f);
	len = ft_wstrlen(str);
	if (f->width && f->width > ft_wstrlen(str))
	{
		if (f->minus)
		{
			ft_putwstr(str);
			ft_put_specific_char(' ', f->width - ft_wstrlen(str));
		}
		else if (f->zero)
		{
			ft_put_specific_char('0', f->width - ft_wstrlen(str));
			ft_putwstr(str);
		}
		else if (f->zero_precision)
			ft_put_specific_char(' ', f->width);
		else
		{
			ft_put_specific_char(' ', f->width - ft_wstrlen(str));
			ft_putwstr(str);
		}
		free(str);
		return (f->width);
	}
	if (f->zero_precision)
	{
		if (f->zero)
			ft_put_specific_char('0', f->width);
		else
			ft_put_specific_char(' ', f->width);
		free(str);
		return (f->width);
	}
	free(str);
	return (ft_putwstr(str));
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
	if (f->zero_precision)
	{
		ft_put_specific_char(' ', f->width);
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
			if (f->zero)
			{
				ft_put_specific_char('0', f->width);
				return (f->width);
			}
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