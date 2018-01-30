/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <nrepak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:08:00 by nrepak            #+#    #+#             */
/*   Updated: 2017/11/19 20:41:13 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *current;
	t_list *new;

	if (!lst || !f)
		return ;
	current = lst;
	while (current)
	{
		new = current->next;
		f(current);
		current = new;
	}
}
