/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percentage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:18:53 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/10 19:05:07 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_percentage(t_flags *f)
{
	if (f->width && f->width > 1)
	{
		if (f->minus)
		{
			ft_putchar('%');
			ft_put_specific_char(' ', f->width - 1);
		}
		else if (f->zero)
		{
			ft_put_specific_char('0', f->width - 1);
			ft_putchar('%');
		}
		else
		{
			ft_put_specific_char(' ', f->width - 1);
			ft_putchar('%');
		}
		return (f->width);
	}
	ft_putchar('%');
	return (1);
}
