/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <nrepak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:35:38 by nrepak            #+#    #+#             */
/*   Updated: 2017/11/19 20:41:03 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*str;
	long	i;
	long	nb;

	i = ft_number_size(n);
	nb = n;
	str = (char *)malloc(sizeof(*str) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	while (nb > 9)
	{
		str[--i] = nb % 10 + 48;
		nb = nb / 10;
	}
	str[--i] = nb + 48;
	return (str);
}
