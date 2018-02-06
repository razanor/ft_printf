/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 13:42:44 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/03 13:43:00 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_collect_for_p(uintmax_t i, t_flags *f)
{
	int len;
	char *str;

	len = ft_base_len(i, 16) + 2;
	if (f->width && f->width > len)
	{
		if (f->minus)
		{
			ft_putstr("0x");
			ft_putstr(str = ft_itoa_unsigned(i, 16));
			ft_put_specific_char(' ', f->width - len);
		}
		else if (f->zero)
		{
			ft_putstr("0x");
			ft_put_specific_char('0', f->width - len);
			ft_putstr(str = ft_itoa_unsigned(i, 16));
		}
		else
		{
			ft_put_specific_char(' ', f->width - len);
			ft_putstr("0x");
			ft_putstr(str = ft_itoa_unsigned(i, 16));
		}
		ft_strdel(&str);
		return (f->width);
	}
	ft_putstr("0x");
	ft_putstr(str = ft_itoa_unsigned(i, 16));
	ft_strdel(&str);
	return (len);
}

int ft_p(va_list lst, t_flags *f)
{
	uintmax_t i;

	i = va_arg(lst, uintmax_t);
	return (ft_collect_for_p(i, f));
}