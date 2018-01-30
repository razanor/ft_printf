/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <nrepak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:21:51 by nrepak            #+#    #+#             */
/*   Updated: 2017/11/19 20:41:21 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	a;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	a = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s[i] == a)
		{
			d[i] = s[i];
			i = i + 1;
			return (d + i);
		}
		d[i] = s[i];
		i++;
	}
	return (NULL);
}
