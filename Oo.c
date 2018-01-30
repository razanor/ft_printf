/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Oo.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:55:33 by nrepak            #+#    #+#             */
/*   Updated: 2018/01/29 14:55:37 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void ft_width(uintmax_t i, t_flags *f, int *width, int *width2)
{
	int len;

	len = 0;
	if (f->slash && !f->precision)
		len++;
	if (f->width && f->width > ft_base_len(i, 8) && f->width > f->precision)
	{
		*width2 = f->width - f->precision;
		*width = f->width - ft_base_len(i, 8);
		if (!f->minus)
		{
		if (!f->precision)
			{	
				if (f->zero)
					ft_put_specific_char('0', *width - len);
				else
					ft_put_specific_char(' ', *width - len);
			}
		else
			ft_put_specific_char(' ', *width2 - len);
		if (f->slash && i && !f->precision)
			ft_putchar('0');
		}
	}
}

static	int ft_collect_for_Oo(uintmax_t i, t_flags *f)
{
	int len;
	int	width;
	int	width2;

	width = 0;
	width2 = 0;
	len = 0;
	ft_width(i, f, &width, &width2);
	if (f->precision && f->precision > ft_base_len(i, 8))
	{
		ft_put_specific_char('0', f->precision - ft_base_len(i, 8));
		ft_putstr(ft_itoa_unsigned(i, 8));
		if (f->minus)
			ft_put_specific_char(' ', width2);
		return (f->precision + width2);
	}
	if (f->slash && i && !f->width)
	{
		ft_putchar('0');
		len++;
	}
	ft_putstr(ft_itoa_unsigned(i, 8));
		if (f->minus)
			ft_put_specific_char(' ', width);
	return (ft_base_len(i, 8) + width + len); 
}
	
int	ft_Oo(va_list lst, char c, t_flags *f)
{
	uintmax_t i;

	i = va_arg(lst, uintmax_t);
	if (c == 'o')
		return (ft_collect_for_Oo((unsigned int)i, f));
	if (c == 'O')
		return (ft_collect_for_Oo(i, f));
	return (0);
}
