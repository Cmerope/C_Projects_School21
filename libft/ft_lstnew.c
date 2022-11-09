/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:48:25 by cmerope           #+#    #+#             */
/*   Updated: 2020/11/24 13:31:38 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*list_new;

	list_new = (t_list*)malloc(sizeof(t_list) * 1);
	if (!list_new)
		return (NULL);
	list_new->content = content;
	list_new->next = NULL;
	return (list_new);
}
