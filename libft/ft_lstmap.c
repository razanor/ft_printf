/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrepak <nrepak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:43:13 by nrepak            #+#    #+#             */
/*   Updated: 2017/11/19 20:41:15 by nrepak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fnew;
	t_list *copy;

	if (!lst || !f)
		return (NULL);
	fnew = f(lst);
	if (!fnew)
		return (NULL);
	lst = lst->next;
	copy = fnew;
	while (lst)
	{
		copy->next = f(lst);
		copy = copy->next;
		lst = lst->next;
	}
	return (fnew);
}
