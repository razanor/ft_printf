/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 19:52:41 by nrepak            #+#    #+#             */
/*   Updated: 2018/01/17 19:52:57 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_len(intmax_t a)
{
	int i;

	i = 1;
	if (a < 0)	
		a = -a;
	if (a <= 9)
		return (i);
	while (a > 9)
	{
		i++;
		a = a / 10;
	}
	return (i); 
}

char *ft_itoa_10(intmax_t n)
{
	char	*str;
	int		len;

	len = ft_count_len(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n < 0)
		n = -n;
	str[len--] = '\0';
	while (n > 9)
	{
		str[len] = n % 10 + 48;
		n = n / 10;
		len--; 
	}
	str[len] = n + 48;
	return (str);
}