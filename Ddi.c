/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 20:16:14 by nrepak            #+#    #+#             */
/*   Updated: 2018/01/28 20:16:17 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int ft_plus_space(intmax_t i, t_flags *f)
{
	if (f->plus)
	{
		if (i >= 0)
			ft_putchar('+');
		else 
			ft_putchar('-');
		return (1);
	}
	if (f->space)
	{
		if (i >= 0)
			ft_putchar(' ');
		else
			ft_putchar('-');
		return (1);
	}
	if (i < 0)
	{
		ft_putchar('-');
		return (1);
	}
	return (0);
}

static	void ft_width(intmax_t i, t_flags *f, int *width, int *width2)
{
	if (f->width && f->width > ft_count_len(i) && f->width > f->precision)
	{
		*width2 = f->width - f->precision;
		*width = f->width - ft_count_len(i);
		if (f->plus || f->space) 
		{
			(*width)--;
			(*width2)--;
		}
		if (!f->minus)
		{
		if (!f->precision)
			{	
				if (f->zero)
					ft_put_specific_char('0', *width);
				else
					ft_put_specific_char(' ', *width);
			}
		else
			ft_put_specific_char(' ', *width2);
		}
	}
}

static int ft_collect_for_Ddi(intmax_t i, t_flags *f)
{
	int len;
	int width;
	int width2;

	width = 0;
	width2 = 0;
	ft_width(i, f, &width, &width2);
	len = ft_plus_space(i, f);
	if (f->precision && f->precision > ft_count_len(i))
	{
		ft_put_specific_char('0', f->precision - ft_count_len(i));
		ft_putstr(ft_itoa_10(i));
		if (f->minus)
			ft_put_specific_char(' ', width2);
		return (f->precision + len + width2);
	}
	ft_putstr(ft_itoa_10(i));
		if (f->minus)
			ft_put_specific_char(' ', width);
	return (ft_count_len(i) + len + width); 
}

int ft_Ddi(va_list lst, char c, t_flags *f)
{	
	intmax_t i;

	i = va_arg(lst, intmax_t);
	if (c == 'd' || c == 'i')	
		return (ft_collect_for_Ddi((int)i, f));
	if (c == 'D')
		return (ft_collect_for_Ddi(i, f));
	return (0);
}
