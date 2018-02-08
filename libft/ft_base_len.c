/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 00:15:04 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/08 15:50:40 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_base_len(uintmax_t value, unsigned int base)
{
	int i;

	i = 1;
	while (value >= base)
	{
		value = value / base;
		i++;
	}
	return (i);
}
