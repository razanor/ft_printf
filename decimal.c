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

static	int ft_zero(int len, intmax_t i, t_flags *f)
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

static char *ft_precision(intmax_t i, char **num, char *str, t_flags *f)
{
	int len;
	int a;

	len = 0;
	a = f->precision - ft_count_len(i);
	ft_plus_space(i, f) == 1 ? (str[len++] = '+') : (str[len] = '\0');
	ft_plus_space(i, f) == 2 ? (str[len++] = '-') : (str[len] = '\0');
	ft_plus_space(i, f) == 3 ? (str[len++] = ' ') : (str[len] = '\0');
	while (a--)
		str[len++] = '0';
	a = 0;
	while ((*num)[a])
		str[len++] = (*num)[a++];
	ft_strdel(&(*num));
	return (str);	
}

static	char *ft_precision_space_plus(intmax_t i, t_flags *f)
{
	char *str;
	char *num;
	int len;
	int flag;
	int b;

	len = 0;
	b = 0;
	num = ft_itoa_10(i);
	ft_plus_space(i, f) ? (flag = 1) : (flag = 0);
	f->precision > ft_count_len(i) ? (str = ft_strnew(f->precision + flag)) :
		(str = ft_strnew(ft_count_len(i) + flag));
	if (f->precision && f->precision > ft_count_len(i))
		return (ft_precision(i, &num, str, f));
	ft_plus_space(i, f) == 1 ? (str[len++] = '+') : (str[len] = '\0');
	ft_plus_space(i, f) == 2 ? (str[len++] = '-') : (str[len] = '\0');
	ft_plus_space(i, f) == 3 ? (str[len++] = ' ') : (str[len] = '\0');		
	while (num[b])
		str[len++] = num[b++];
	ft_strdel(&num);
	return (str);
}

static int ft_width(intmax_t i, int len, char **str, t_flags *f)
{
	if (f->minus)
	{
		write (1, *str, len);
		ft_put_specific_char(' ', f->width - len);
	}
	else if (f->zero && !f->precision && !f->zero_precision)
	{
		ft_strdel(&(*str));
		return (ft_zero(len, i, f));
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

static	int ft_collect_for_Ddi(intmax_t i, t_flags *f)
{
	char *str;
	int	 len;

	str = ft_precision_space_plus(i, f);
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

int ft_decimal(va_list lst, char c, t_flags *f)
{	
	intmax_t i;

	i = va_arg(lst, intmax_t);
	if (c == 'd' || c == 'i')
	{	
		CAST ? (i = ft_cast_to_signed(i, f)) : (i = (int)i);	
		return (ft_collect_for_Ddi(i, f));
	}
	if (c == 'D')
		return (ft_collect_for_Ddi(i, f));
	return (0);
}
