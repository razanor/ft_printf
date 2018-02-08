/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kostils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:18:27 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/08 15:48:59 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_collect_flags(char c, t_flags *f, const char ***str, int n_width)
{
	if (c == '#')
		f->slash = 1;
	if (c == '-')
		f->minus = 1;
	if (c == '+')
		f->plus = 1;
	if (c == ' ')
		f->space = 1;
	if (c == '0')
		f->zero = 1;
	if (n_width)
	{
		if (ft_isdigit(c) && c != '0')
		{
			while (**str && ft_isdigit(***str))
				(**str)++;
			(**str)--;
		}
	}
}

void		ft_find_cast_flags(const char *str, t_flags *f)
{
	int i;

	i = 0;
	while (str[i] && !(ft_conversions(str[i])))
	{
		if (str[i] == 'l' && str[i + 1] == 'l')
		{
			f->ll = 1;
			i = i + 2;
		}
		if (str[i] == 'h' && str[i + 1] == 'h')
		{
			f->hh = 1;
			i = i + 2;
		}
		if (str[i] == 'l')
			f->l = 1;
		if (str[i] == 'h')
			f->h = 1;
		if (str[i] == 'j')
			f->j = 1;
		if (str[i] == 'z')
			f->z = 1;
		i++;
	}
}

intmax_t	ft_cast_to_signed(intmax_t i, t_flags *f)
{
	if (f->z)
		return ((size_t)i);
	if (f->j)
		return ((intmax_t)i);
	if (f->ll)
		return ((long long)i);
	if (f->l)
		return ((long)i);
	if (f->h)
		return ((short)i);
	if (f->hh)
		return ((char)i);
	return (0);
}

uintmax_t	ft_cast_to_unsigned(uintmax_t i, t_flags *f)
{
	if (f->z)
		return ((size_t)i);
	if (f->j)
		return ((uintmax_t)i);
	if (f->ll)
		return ((unsigned long long)i);
	if (f->l)
		return ((unsigned long)i);
	if (f->h)
		return ((unsigned short)i);
	if (f->hh)
		return ((unsigned char)i);
	return (0);
}

char		*ft_upper_lower_string(uintmax_t i, char c)
{
	char *num;

	if (c == 'X')
		ft_upper(num = ft_itoa_unsigned(i, 16));
	else
		num = ft_itoa_unsigned(i, 16);
	return (num);
}
