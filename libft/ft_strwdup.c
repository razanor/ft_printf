/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 23:36:00 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/08 16:01:07 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_strwdup(wchar_t *s)
{
	wchar_t	*str;
	int		i;
	int		len;

	len = ft_wstrlen(s);
	i = 0;
	if (!(str = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
