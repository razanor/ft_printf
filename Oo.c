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

static int ft_zero(uintmax_t i, t_flags *f)
{
	ft_put_specific_char('0', f->width - ft_base_len(i, 8));
	ft_putstr(ft_itoa_unsigned(i, 8));
	return (f->width);
}

static char		*ft_precision_slash(uintmax_t i, t_flags *f)
{
	char *str;
	char *num;
	int  len;
	int  flag;
	int  a;

	len = 0;
	num = ft_itoa_unsigned(i, 8);
	(f->slash && i && f->precision < ft_base_len(i, 8)) ? (flag = 1) : (flag = 0);
	f->precision > ft_base_len(i, 8) ? (str = ft_strnew(f->precision)) :
		(str = ft_strnew(ft_base_len(i, 8) + flag));
	if (f->precision && f->precision > ft_base_len(i, 8))
	{
		a = f->precision - ft_base_len(i, 8);
		while (a--)
			str[len++] = '0';
		while (*num)
			str[len++] = *num++;
		return (str);
	}
	(flag == 1) ? (str[len++] = '0') : (str[len] = '\0');
	while (*num)
		str[len++] = *num++;
	return (str);
}

static	int ft_collect_for_Oo(uintmax_t i, t_flags *f)
{
	char *str;
	int	 len;

	str = ft_precision_slash(i, f);
	len = ft_strlen(str);
	if (f->width && f->width > len)
	{
		if (f->minus)
		{
			ft_putstr(str);
			ft_put_specific_char(' ', f->width - len);
		}
		else if (f->zero && !f->precision)
			return (ft_zero(i, f));
		else
		{
			ft_put_specific_char(' ', f->width - len);
			ft_putstr(str);
		}
		free(str);
		return (f->width);
	}
	ft_putstr(str);
	free(str);
	return (len);
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
