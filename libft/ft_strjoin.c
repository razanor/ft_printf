/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <nrepak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:11:43 by nrepak            #+#    #+#             */
/*   Updated: 2017/11/19 20:45:32 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*fnew;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	fnew = (char *)malloc(sizeof(*fnew) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!fnew)
		return (NULL);
	while (*s1)
	{
		fnew[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		fnew[i] = *s2;
		s2++;
		i++;
	}
	fnew[i] = '\0';
	return (fnew);
}
