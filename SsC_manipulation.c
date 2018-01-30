/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:17:52 by nrepak            #+#    #+#             */
/*   Updated: 2018/01/21 19:18:09 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_count_bytes(wchar_t c)
{
	if (c <= 127)
		return (1);
	else if (c <= 2047)
		return (2);
	else if (c <= 65535)
		return (3);
	else
		return (4);
}

int	ft_wstrlen(wchar_t *str)
{	
	int i;
	int len;

	len = 0;
	i = 0;
	while (str[i])
	{
		len = len + ft_count_bytes(str[i]);
		i++;
	}
	return (len);
}

int	ft_putwchar(wchar_t c)
{
	int len;

	len = ft_count_bytes(c);
	if (len == 1)
		ft_putchar(c);
	else if (len == 2)
	{
		ft_putchar((c >> 6) | 0xC0);
		ft_putchar((c & 0x3F) | 0x80);
	}
	else if (len == 3)
	{
		ft_putchar((c >> 12) | 0xE0);
		ft_putchar(((c >> 6) & 0x3F) | 0x80);
		ft_putchar((c & 0x3F) | 0x80);
	}
	else if (len == 4)
	{
		ft_putchar((c >> 18) | 0xF0);
		ft_putchar(((c >> 12) & 0x3F) | 0x80);
		ft_putchar(((c >> 6) & 0x3F) | 0x80);
		ft_putchar((c & 0x3F) | 0x80);
	}
	return (len);
}

int	ft_putwstr(wchar_t *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i])
	{
		len = len + ft_putwchar(str[i]);
		i++;
	}
	return (len);
}

void	ft_put_specific_char(char c, int i)
{
	while (i)
	{
		write(1, &c, 1);
		i--;
	}
}