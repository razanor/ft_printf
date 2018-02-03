/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:29:13 by nrepak            #+#    #+#             */
/*   Updated: 2018/01/16 19:08:03 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <inttypes.h>

#include <locale.h>
#include <stdio.h>

typedef	struct s_flags
{
	int 	slash;
	int     minus;
	int 	plus;
	int 	space;
	int 	zero;
	int 	width;
	int 	precision;
	int     hh;
	int     h;
	int     l;
	int     ll;
	int     j;
	int     z;
}				t_flags;

int		ft_printf(const char *str, ...);
int 	ft_Cc(va_list lst, char c, t_flags *f);
int		ft_Ss(va_list lst, char c, t_flags *f);
int		ft_Xx(va_list lst, char c, t_flags *f);
int		ft_Oo(va_list lst, char c, t_flags *f);
int 	ft_Uu(va_list lst, char c, t_flags *f);
int 	ft_Ddi(va_list lst, char c, t_flags *f);
int 	ft_p(va_list lst, t_flags *f);
char 	*ft_itoa_10(intmax_t n);
int		ft_count_len(intmax_t a);
char 	*ft_itoa_unsigned(uintmax_t value, unsigned int base);
int		ft_base_len(uintmax_t value, unsigned int base);
int 	ft_putwchar(wchar_t c);
int		ft_putwstr(wchar_t *str);
int		ft_check_width(const char *str);
int		ft_check_precision(const char *str);
int		ft_conversions(char c);
int		ft_is_conversions(const char *str);
void	ft_zero_to_all(t_flags *f);
void	ft_put_specific_char(char c, int i);
int 	ft_count_bytes(wchar_t c);
int		ft_wstrlen(wchar_t *str);
void	ft_collect_flags(char c, t_flags *f, const char ***str, int n_width);
int 	ft_percentage(t_flags *f);
int 	ft_plus_space(intmax_t i, t_flags *f);
void	ft_upper(char *str);
void	ft_find_cast_flags(const char *str, t_flags *f);
int		ft_if_cast_flags(t_flags *f);
intmax_t ft_cast_to_signed(intmax_t i, t_flags *f);
uintmax_t ft_cast_to_unsigned(uintmax_t i, t_flags *f);


#endif
