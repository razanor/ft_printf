/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <nrepak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:58:33 by nrepak            #+#    #+#             */
/*   Updated: 2017/11/19 20:41:23 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	a;
	size_t			i;

	str = (unsigned char *)s;
	a = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == a)
			return (str + i);
		i++;
	}
	return (NULL);
}
