/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 20:15:51 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/07 16:17:34 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_precision(char *s, t_flags *f)
{
	char *str;

	if (f->precision && f->precision < (int)ft_strlen(s))
		str = ft_strsub(s, 0, f->precision);
	else
		str = ft_strdup(s);
	return (str);
}

static int		ft_width(int len, char **str, t_flags *f)
{
	if (f->minus)
	{
		write(1, *str, len);
		ft_put_specific_char(' ', f->width - len);
	}
	else if (f->zero)
	{
		ft_put_specific_char('0', f->width - len);
		write(1, *str, len);
	}
	else if (f->zero_precision)
		ft_put_specific_char(' ', f->width);
	else
	{
		ft_put_specific_char(' ', f->width - len);
		write(1, *str, len);
	}
	ft_strdel(&(*str));
	return (f->width);
}

int				ft_collect_for_string(char *s, t_flags *f)
{
	char	*str;
	int		len;

	str = ft_precision(s, f);
	len = ft_strlen(str);
	if (f->width && f->width > len)
		return (ft_width(len, &str, f));
	if (f->zero_precision)
	{
		ft_put_specific_char(' ', f->width);
		ft_strdel(&str);
		return (f->width);
	}
	write(1, str, len);
	ft_strdel(&str);
	return (len);
}

int				ft_string(va_list lst, char c, t_flags *f)
{
	char *s;

	if (c == 's')
	{
		if (CAST)
			return (ft_collect_for_wide_string((va_arg(lst, wchar_t*)), f));
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
		return (ft_collect_for_string(s, f));
	}
	if (c == 'S')
		return (ft_wide_string(lst, f));
	return (1);
}
