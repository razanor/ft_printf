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

static	int ft_collect_for_s(char *s, t_flags *f)
{
	if (f->width && f->width > (int)ft_strlen(s))
	{
		if (f->minus)
		{
			ft_putstr(s);
			ft_put_specific_char(' ', f->width - ft_strlen(s));
		}
		else
		{
			ft_put_specific_char(' ', f->width - ft_strlen(s));
			ft_putstr(s);
		}
		return (f->width);
	}
	ft_putstr(s);
	return (ft_strlen(s));
}

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

int	ft_Ss(va_list lst, char c, t_flags *f)
{
	char *s;
	wchar_t *a;

	if (c == 's')
	{
		s = va_arg(lst, char*);
		return (ft_collect_for_s(s, f));
	}
	if (c == 'S')
	{
		a = va_arg(lst, wchar_t*);
		return (ft_collect_for_S(a, f));
	}
	return (1);
}