/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <nrepak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:16:33 by nrepak            #+#    #+#             */
/*   Updated: 2017/11/12 21:40:55 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	end_white(char const *s)
{
	int		end;

	end = ft_strlen(s) - 1;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
		end--;
	return (end);
}

static int	start_white(char const *s)
{
	int		start;

	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	return (start);
}

char		*ft_strtrim(char const *s)
{
	int		end;
	int		start;
	int		a;
	char	*fnew;

	a = 0;
	if (!s)
		return (NULL);
	end = end_white(s);
	start = start_white(s);
	if (end < 0)
	{
		end = -1;
		start = 0;
	}
	fnew = (char *)malloc(sizeof(*fnew) * (end - start) + 2);
	if (!fnew)
		return (NULL);
	while (start < end + 1)
		fnew[a++] = s[start++];
	fnew[a] = '\0';
	return (fnew);
}
