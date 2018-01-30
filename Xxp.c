/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ndecimal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:09:42 by nrepak            #+#    #+#             */
/*   Updated: 2018/01/24 17:10:01 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_Xx(va_list lst, char c, t_flags *f)
{
	uintmax_t i;
	char *str;
	int a;

	f->width = 0; // для перевірки 
	a = 0;
	i = va_arg(lst, uintmax_t);
	if (c == 'x')
		ft_putstr(ft_itoa_unsigned((unsigned int)i, 16));
	if (c == 'X')
	{
		str = ft_itoa_unsigned((unsigned int)i, 16);
		while (str[a])
		{
			if (ft_isalpha(str[a]))
				str[a] = ft_toupper(str[a]);
			a++;
		}
		ft_putstr(str);
	}
	return (ft_base_len((unsigned int)i, 16));
}

int ft_p(va_list lst, t_flags *f)
{
	uintmax_t i;

	f->width = 0; // для перевірки 
	i = va_arg(lst, uintmax_t);
	ft_putstr("0x");
	ft_putstr(ft_itoa_unsigned(i, 16));
	return (ft_base_len(i, 16) + 2);
}