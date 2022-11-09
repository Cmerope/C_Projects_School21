/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 20:20:57 by cmerope           #+#    #+#             */
/*   Updated: 2020/11/14 16:15:58 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *tmp;

	tmp = (char*)s;
	if (!ft_strchr(tmp, c))
		return (0);
	while (*tmp)
		tmp++;
	while (*tmp != (char)c)
		tmp--;
	return (tmp);
}
