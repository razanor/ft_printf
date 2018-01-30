/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 20:15:38 by nrepak            #+#    #+#             */
/*   Updated: 2018/01/28 20:15:39 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_collect_for_c(char i, t_flags *f)
{
	if (f->width)
	{
		if (f->minus)
		{
			ft_putchar(i);
			ft_put_specific_char(' ', f->width - 1);
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

static int ft_collect_for_C(wchar_t a, t_flags *f)
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

int ft_Cc(va_list lst, char c, t_flags *f)
{
	char i;
	wchar_t a;

	if (c == 'c')
	{
		i = va_arg(lst, int);
		return (ft_collect_for_c(i, f));
	}
	if (c == 'C')
	{
		a = va_arg(lst, wchar_t);
		return (ft_collect_for_C(a, f));
	}
	return (0);
}
