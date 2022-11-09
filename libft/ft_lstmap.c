/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:28:39 by cmerope           #+#    #+#             */
/*   Updated: 2020/11/24 13:34:30 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp_list;

	if (!lst || !(tmp = ft_lstnew(f(lst->content))))
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		if (!(tmp_list = ft_lstnew(f(lst->content))))
			ft_lstclear(&tmp, del);
		ft_lstadd_back(&tmp, tmp_list);
		lst = lst->next;
	}
	return (tmp);
}
