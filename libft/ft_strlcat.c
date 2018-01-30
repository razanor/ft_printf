/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:27:35 by nrepak            #+#    #+#             */
/*   Updated: 2017/11/10 21:52:09 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t len;
	size_t i;
	size_t a;

	len = ft_strlen(dst);
	a = len;
	i = 0;
	if (dstsize <= len)
		return (dstsize + ft_strlen(src));
	while (dstsize - len - 1 && src[i])
	{
		dst[a] = src[i];
		a++;
		i++;
		dstsize--;
	}
	dst[a] = '\0';
	return (len + ft_strlen(src));
}
