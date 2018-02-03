/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kostils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:18:27 by nrepak            #+#    #+#             */
/*   Updated: 2018/01/29 18:18:34 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_collect_flags(char c, t_flags *f, const char ***str, int n_width)
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

