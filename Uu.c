/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:08:23 by nrepak            #+#    #+#             */
/*   Updated: 2018/01/24 17:08:38 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void ft_width(uintmax_t i, t_flags *f, int *width, int *width2)
{
	if (f->width && f->width > ft_base_len(i, 10) && f->width > f->precision)
	{
		*width2 = f->width - f->precision;
		*width = f->width - ft_base_len(i, 10);
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

static int ft_collect_for_Uu(uintmax_t i, t_flags *f)
{
	int width;
	int width2;

	width = 0;
	width2 = 0;
	ft_width(i, f, &width, &width2);
	if (f->precision && f->precision > ft_base_len(i, 10))
	{
		ft_put_specific_char('0', f->precision - ft_base_len(i, 10));
		ft_putstr(ft_itoa_unsigned(i, 10));
		if (f->minus)
			ft_put_specific_char(' ', width2);
		return (f->precision + width2);
	}
	ft_putstr(ft_itoa_unsigned(i, 10));
		if (f->minus)
			ft_put_specific_char(' ', width);
	return (ft_base_len(i, 10) + width); 
}

int ft_Uu(va_list lst, char c, t_flags *f)
{
	uintmax_t i;

	i = va_arg(lst, uintmax_t);
	if (c == 'u')
	{
		ft_if_cast_flags(f) ? (i = ft_cast_to_unsigned(i, f)) : (i = (unsigned int)i);	
		return (ft_collect_for_Uu(i, f)); 
	}
	if (c == 'U')
		return (ft_collect_for_Uu(i, f));
	return (0); 
}
