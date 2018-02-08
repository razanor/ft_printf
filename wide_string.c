/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:53:50 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/07 16:26:51 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static wchar_t		*ft_precision(wchar_t *a, t_flags *f)
{
	int			size;
	int			b;
	wchar_t		*str;

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

static int			ft_width(int len, wchar_t **str, t_flags *f)
{
	if (f->minus)
	{
		ft_putwstr(*str);
		ft_put_specific_char(' ', f->width - len);
	}
	else if (f->zero)
	{
		ft_put_specific_char('0', f->width - len);
		ft_putwstr(*str);
	}
	else if (f->zero_precision)
		ft_put_specific_char(' ', f->width);
	else
	{
		ft_put_specific_char(' ', f->width - len);
		ft_putwstr(*str);
	}
	free(*str);
	return (f->width);
}

int					ft_collect_for_wide_string(wchar_t *a, t_flags *f)
{
	wchar_t		*str;
	int			len;

	str = ft_precision(a, f);
	len = ft_wstrlen(str);
	if (f->width && f->width > len)
		return (ft_width(len, &str, f));
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

int					ft_wide_string(va_list lst, t_flags *f)
{
	wchar_t		*a;
	int			i;

	i = 0;
	if (!(a = va_arg(lst, wchar_t*)))
	{
		ft_putstr("(null)");
		return (6);
	}
	if (MB_CUR_MAX == 1)
	{
		while (a[i])
		{
			if (a[i] > 255)
				return (-1);
			i++;
		}
	}
	return (ft_collect_for_wide_string(a, f));
}
