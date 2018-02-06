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

// static	void ft_width(uintmax_t i, t_flags *f, int *width, int *width2)
// {
// 	if (f->width && f->width > ft_base_len(i, unsigned) && f->width > f->precision)
// 	{
// 		*width2 = f->width - f->precision;
// 		*width = f->width - ft_base_len(i, unsigned);
// 		if (!f->minus)
// 		{
// 		if (!f->precision)
// 			{	
// 				if (f->zero)
// 					ft_put_specific_char('0', *width);
// 				else
// 					ft_put_specific_char(' ', *width);
// 			}
// 		else
// 			ft_put_specific_char(' ', *width2);
// 		}
// 	}
// }

// static int ft_collect_for_Uu(uintmax_t i, t_flags *f)
// {
// 	int width;
// 	int width2;
// 	char *str;

// 	width = 0;
// 	width2 = 0;
// 	ft_width(i, f, &width, &width2);
// 	if (f->precision && f->precision > ft_base_len(i, unsigned))
// 	{
// 		ft_put_specific_char('0', f->precision - ft_base_len(i, unsigned));
// 		ft_putstr(str = ft_itoa_unsigned(i, unsigned));
// 		if (f->minus)
// 			ft_put_specific_char(' ', width2);
// 		ft_strdel(&str);
// 		return (f->precision + width2);
// 	}
// 	ft_putstr(str = ft_itoa_unsigned(i, unsigned));
// 	if (f->minus)
// 		ft_put_specific_char(' ', width);
// 	ft_strdel(&str);
// 	return (ft_base_len(i, unsigned) + width); 
// }

static	int ft_zero(uintmax_t i, t_flags *f, int len)
{
	char *str;

	ft_put_specific_char('0', f->width - len);
	ft_putstr(str = ft_itoa_unsigned(i, 10));
	ft_strdel(&str);
	return (f->width);
}

static	char *ft_precision(uintmax_t i, t_flags *f)
{
	char *str;
	char *num;
	int len;
	int b;
	int a;

	len = 0;
	b = 0;
	num = ft_itoa_unsigned(i, 10);
	f->precision > ft_base_len(i, 10) ? (str = ft_strnew(f->precision)) :
		(str = ft_strnew(ft_base_len(i, 10)));
	if (f->precision && f->precision > ft_base_len(i, 10))
	{
		a = f->precision - ft_base_len(i, 10);
		while (a--)
			str[len++] = '0';
		a = 0;
		while (num[a])
			str[len++] = num[a++];
		ft_strdel(&num);
		return (str);	
	}
	while (num[b])
		str[len++] = num[b++];
	ft_strdel(&num);
	return (str);
}

static int ft_width(uintmax_t i, int len, char **str, t_flags *f)
{
	if (f->minus)
	{
		write (1, *str, len);
		ft_put_specific_char(' ', f->width - len);
	}
	else if (f->zero && !f->precision && !f->zero_precision)
	{
		ft_strdel(&(*str));
		return (ft_zero(i, f, len));
	}
	else if (f->zero_precision && i == 0)
	{
		ft_strdel(&(*str));
		ft_put_specific_char(' ', f->width - len + 1);
		return (f->width);
	}
	else
	{
		ft_put_specific_char(' ', f->width - len);
		write (1, *str, len);
	}
	ft_strdel(&(*str));
	return (f->width);
}

static int ft_collect_for_Uu(uintmax_t i, t_flags *f)
{
	char *str;
	int	 len;

	str = ft_precision(i, f);
	len = ft_strlen(str);
	if (f->width && f->width > len)
		return (ft_width(i, len, &str, f));
	if (f->zero_precision && i == 0)
	{
		ft_strdel(&str);
		return (0);
	}
	write (1, str, len);
	ft_strdel(&str);
	return (len);
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
