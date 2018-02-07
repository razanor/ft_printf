/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 12:41:49 by nrepak            #+#    #+#             */
/*   Updated: 2018/02/07 15:35:32 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_find_len_w(const char *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i] && str[i] != '.' && !(ft_conversions(str[i])))
	{
		if (ft_isdigit(str[i]))
			len++;
		i++;
	}
	return (len);
}

static	int		ft_find_len_p(const char *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i] && str[i] != '.' && !(ft_conversions(str[i])))
		i++;
	while (str[i] && !(ft_conversions(str[i])))
	{
		if (ft_isdigit(str[i]))
			len++;
		i++;
	}
	return (len);
}

int				ft_check_width(const char *str)
{
	char	*num;
	int		i;
	int		j;

	i = 0;
	j = 0;
	num = ft_strnew(ft_find_len_w(str) + 1);
	while (str[i] && str[i] != '.' && !(ft_conversions(str[i])))
	{
		if (ft_isdigit(str[i]))
		{
			num[j] = str[i];
			j++;
		}
		i++;
	}
	num[j] = '\0';
	j = ft_atoi(num);
	ft_strdel(&num);
	return (j);
}

int				ft_check_precision(const char *str)
{
	char	*num;
	int		i;
	int		j;

	i = 0;
	j = 0;
	num = ft_strnew(ft_find_len_p(str) + 1);
	while (str[i] && str[i] != '.' && !(ft_conversions(str[i])))
		i++;
	while (str[i] && !(ft_conversions(str[i])))
	{
		if (ft_isdigit(str[i]))
		{
			num[j] = str[i];
			j++;
		}
		i++;
	}
	num[j] = '\0';
	j = ft_atoi(num);
	ft_strdel(&num);
	return (j);
}

void			ft_zero_precision(const char *str, t_flags *f)
{
	int i;

	i = 0;
	f->zero_precision = 0;
	while (str[i] && !(ft_conversions(str[i])))
	{
		if (str[i] == '.' && (!(ft_isdigit(str[i + 1])) || str[i + 1] == '0'))
			f->zero_precision = 1;
		i++;
	}
}
