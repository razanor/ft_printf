/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:10:04 by nrepak            #+#    #+#             */
/*   Updated: 2017/11/11 21:20:38 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*fnew;

	i = 0;
	if (!s || !f)
		return (NULL);
	fnew = (char*)malloc(sizeof(*fnew) * ft_strlen(s) + 1);
	if (!fnew)
		return (NULL);
	while (s[i])
	{
		fnew[i] = f(i, s[i]);
		i++;
	}
	fnew[i] = '\0';
	return (fnew);
}
