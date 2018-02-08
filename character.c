/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 20:15:38 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/07 15:48:49 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_collect_for_char(char i, t_flags *f)
{
	if (f->width)
	{
		if (f->minus)
		{
			ft_putchar(i);
			ft_put_specific_char(' ', f->width - 1);
		}
		else if (f->zero)
		{
			ft_put_specific_char('0', f->width - 1);
			ft_putchar(i);
		}
		else
		{
			ft_put_specific_char(' ', f->width - 1);
			ft_putchar(i);
		}
		return (f->width);
	}
	ft_putchar(i);
	return (1);
}

static int		ft_collect_for_wchar(wchar_t a, t_flags *f)
{
	if (f->width)
	{
		if (f->minus)
		{
			ft_putwchar(a);
			ft_put_specific_char(' ', f->width - ft_count_bytes(a));
		}
		else
		{
			ft_put_specific_char(' ', f->width - ft_count_bytes(a));
			ft_putwchar(a);
		}
		return (f->width);
	}
	return (ft_putwchar(a));
}

int				ft_character(va_list lst, char c, t_flags *f)
{
	char	i;
	wchar_t	a;

	if (c == 'c')
	{
		if (CAST)
			return (ft_collect_for_wchar(va_arg(lst, wchar_t), f));
		i = va_arg(lst, int);
		return (ft_collect_for_char(i, f));
	}
	if (c == 'C')
	{
		if (MB_CUR_MAX == 1)
		{
			a = (va_arg(lst, wchar_t));
			if (a > 255)
				return (-1);
			else
				return (ft_collect_for_char((char)a, f));
		}
		a = va_arg(lst, wchar_t);
		return (ft_collect_for_wchar(a, f));
	}
	return (0);
}
