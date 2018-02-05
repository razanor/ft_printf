/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 19:04:54 by nrepak            #+#    #+#             */
/*   Updated: 2018/01/16 19:05:41 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define MACRO "%d\n", 200

int main(void)
{
	int a;
	int *d;

	wchar_t *c = NULL;
	setlocale(LC_ALL, " ");
	a = ft_printf("%S", c);
	printf("%d\n", a);
	a = printf("%S", c);
	printf("%d\n", a);
	return (0);
}
