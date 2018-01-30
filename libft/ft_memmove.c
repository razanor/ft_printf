/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <nrepak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:00:50 by nrepak            #+#    #+#             */
/*   Updated: 2017/11/19 20:41:33 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *s;
	unsigned char *d;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (s < d)
	{
		while (len)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	else
		d = ft_memcpy(d, s, len);
	return (d);
}
