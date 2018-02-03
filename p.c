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

int ft_p(va_list lst, t_flags *f)
{
	uintmax_t i;

	f->width = 0; // для перевірки 
	i = va_arg(lst, uintmax_t);
	ft_putstr("0x");
	ft_putstr(ft_itoa_unsigned(i, 16));
	return (ft_base_len(i, 16) + 2);
}