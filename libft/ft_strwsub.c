/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 23:37:13 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/08 16:05:15 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_strwsub(wchar_t *s, unsigned int start, unsigned int len)
{
	unsigned int	i;
	wchar_t			*sub;

	i = 0;
	if (!(sub = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1))))
		return (NULL);
	while (s[start] && i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
