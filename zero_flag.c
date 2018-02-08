/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 22:04:47 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/08 15:47:02 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_zero_decimal(int len, intmax_t i, t_flags *f)
{
	char *str;

	if (ft_plus_space(i, f))
	{
		if (ft_plus_space(i, f) == 1)
			ft_putchar('+');
		if (ft_plus_space(i, f) == 2)
			ft_putchar('-');
		if (ft_plus_space(i, f) == 3)
			ft_putchar(' ');
	}
	ft_put_specific_char('0', f->width - len);
	ft_putstr(str = ft_itoa_10(i));
	ft_strdel(&str);
	return (f->width);
}

int		ft_zero_hexadecimal(int len, uintmax_t i, t_flags *f, char c)
{
	int		flag;
	char	*str;

	str = ft_upper_lower_string(i, c);
	flag = (f->slash && i) ? 2 : 0;
	if (flag)
		c == 'X' ? (ft_putstr("0X")) : (ft_putstr("0x"));
	ft_put_specific_char('0', f->width - len);
	write(1, str, ft_strlen(str));
	ft_strdel(&str);
	return (f->width);
}

int		ft_zero_octal(uintmax_t i, t_flags *f)
{
	char *str;

	ft_put_specific_char('0', f->width - ft_base_len(i, 8));
	ft_putstr(str = ft_itoa_unsigned(i, 8));
	ft_strdel(&str);
	return (f->width);
}

int		ft_zero_pointer(uintmax_t i, t_flags *f, int len)
{
	char *str;

	ft_putstr("0x");
	ft_put_specific_char('0', f->width - len - 2);
	ft_putstr(str = ft_itoa_unsigned(i, 16));
	ft_strdel(&str);
	return (f->width);
}

int		ft_zero_unsigned_decimal(uintmax_t i, t_flags *f, int len)
{
	char *str;

	ft_put_specific_char('0', f->width - len);
	ft_putstr(str = ft_itoa_unsigned(i, 10));
	ft_strdel(&str);
	return (f->width);
}
