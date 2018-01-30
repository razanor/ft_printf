/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <nrepak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:39:38 by nrepak            #+#    #+#             */
/*   Updated: 2017/11/19 20:47:19 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystak, const char *needle)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	len = ft_strlen(needle);
	if (!len)
		return ((char*)haystak);
	while (haystak[i])
	{
		if (haystak[i] == needle[j])
		{
			if (ft_memcmp(haystak + i, needle, len) == 0)
				return ((char*)haystak + i);
		}
		i++;
	}
	return (NULL);
}
