/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <nrepak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:21:07 by nrepak            #+#    #+#             */
/*   Updated: 2017/11/19 18:30:48 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystak, const char *needle, size_t len)
{
	if (!ft_strlen(needle))
		return ((char *)haystak);
	while (*haystak && len)
	{
		if (*haystak == *needle &&
	ft_strncmp(haystak, needle, ft_strlen(needle)) == 0)
		{
			if (ft_strlen(needle) > len)
				return (NULL);
			return ((char *)haystak);
		}
		haystak++;
		len--;
	}
	return (NULL);
}
