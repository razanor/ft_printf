/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <nrepak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:34:28 by nrepak            #+#    #+#             */
/*   Updated: 2017/11/19 20:40:46 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	blank(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' ||
	c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int					flag;
	unsigned long long	num;

	flag = 1;
	num = 0;
	while (blank(*str))
		str++;
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - 48;
		if (num >= 9223372036854775807 && flag == 1)
			return (-1);
		if (num > 9223372036854775807 && flag == -1)
			return (0);
		str++;
	}
	return ((int)num * flag);
}
