/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:17:55 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/07 15:17:04 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conversions(char c)
{
	if (c == '%')
		return (1);
	if (c == 'D' || c == 'd' || c == 'i')
		return (2);
	if (c == 'C' || c == 'c')
		return (3);
	if (c == 'S' || c == 's')
		return (4);
	if (c == 'X' || c == 'x')
		return (5);
	if (c == 'O' || c == 'o')
		return (6);
	if (c == 'U' || c == 'u')
		return (7);
	if (c == 'p')
		return (8);
	return (0);
}

int		ft_plus_space(intmax_t i, t_flags *f)
{
	if (f->plus)
	{
		if (i >= 0)
			return (1);
		else
			return (2);
	}
	if (f->space)
	{
		if (i >= 0)
			return (3);
		else
			return (2);
	}
	if (i < 0)
		return (2);
	return (0);
}

int		ft_is_conversions(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		while (str[i] == 'h' || str[i] == 'l' || str[i] == 'j' || str[i] == 'z')
			i++;
		if ((ft_isalpha(str[i]) || str[i] == '%'))
		{
			if (ft_conversions(str[i]))
				return (1);
			else
				break ;
		}
		i++;
	}
	return (0);
}

int		ft_is_flags(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+')
		return (1);
	else if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	else
		return (0);
}

void	ft_zero_to_all(t_flags *f)
{
	f->slash = 0;
	f->minus = 0;
	f->plus = 0;
	f->space = 0;
	f->zero = 0;
	f->hh = 0;
	f->h = 0;
	f->l = 0;
	f->ll = 0;
	f->j = 0;
	f->z = 0;
}
