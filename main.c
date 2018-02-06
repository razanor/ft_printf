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
#include <locale.h>

#define MACRO "%d\n", 200

int main(void)
{
	int a;
	int *d;
	setlocale(LC_ALL, "");
	a = ft_printf("%jhd", 9223372036854775807);
	printf("%d\n", a);
	a = printf("%jhd", 9223372036854775807);
	printf("%d\n", a);
	
	// wchar_t c = L'暖';
	// wchar_t b = L'ح';
	// setlocale(LC_ALL, " ");
	return (0);
}
