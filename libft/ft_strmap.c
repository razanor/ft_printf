/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <nrepak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:26:22 by nrepak            #+#    #+#             */
/*   Updated: 2017/11/19 20:46:04 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*fnew;

	i = 0;
	if (!s || !f)
		return (NULL);
	fnew = (char *)malloc(sizeof(*fnew) * ft_strlen(s) + 1);
	if (!fnew)
		return (NULL);
	while (s[i])
	{
		fnew[i] = f(s[i]);
		i++;
	}
	fnew[i] = '\0';
	return (fnew);
}
