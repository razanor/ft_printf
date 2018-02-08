/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:57:44 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/08 16:06:04 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_letter(uintmax_t value, int len, char **num)
{
	if (value == 10)
		(*num)[len] = 'a';
	if (value == 11)
		(*num)[len] = 'b';
	if (value == 12)
		(*num)[len] = 'c';
	if (value == 13)
		(*num)[len] = 'd';
	if (value == 14)
		(*num)[len] = 'e';
	if (value == 15)
		(*num)[len] = 'f';
}

static void		ft_transform(uintmax_t value, unsigned int base,
				int len, char **num)
{
	while (value > base - 1)
	{
		if (value % base >= 10 && value % base <= 15 && base > 10)
			ft_letter(value % base, len, num);
		else
			(*num)[len] = value % base + 48;
		value = value / base;
		len--;
	}
	if (value >= 10 && value <= 15 && base > 10)
		ft_letter(value, len, num);
	else
		(*num)[len] = value + 48;
}

char			*ft_itoa_unsigned(uintmax_t value, unsigned int base)
{
	int		len;
	char	*num;

	len = ft_base_len(value, base);
	if (!(num = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	num[len--] = '\0';
	ft_transform(value, base, len, &num);
	return (num);
}
