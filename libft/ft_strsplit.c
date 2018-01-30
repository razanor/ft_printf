/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <nrepak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:11:16 by nrepak            #+#    #+#             */
/*   Updated: 2017/11/19 21:02:51 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_c(const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] == c)
			j++;
		else
		{
			i++;
			if (s[j + 1] == c || s[j + 1] == '\0')
				return (i);
			j++;
		}
	}
	return (i);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**new;
	char	*word;
	int		i;
	int		w;
	int		a;

	a = 0;
	if (!s)
		return (NULL);
	w = ft_count_w(s, c);
	if (!(new = (char**)malloc(sizeof(*new) * (w + 1))))
		return (NULL);
	while (a++ < w)
	{
		i = 0;
		while (*s == c)
			s++;
		word = (char *)ft_memalloc(count_c(s, c) + 1);
		while (*s != c && *s)
			word[i++] = *s++;
		word[i] = '\0';
		*new++ = word;
	}
	*new = NULL;
	return (new - w);
}
