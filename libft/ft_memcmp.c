/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:38:11 by cmerope           #+#    #+#             */
/*   Updated: 2020/11/14 15:25:57 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*new1;
	unsigned char	*new2;
	size_t			i;

	new1 = (unsigned char*)s1;
	new2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (new1[i] != new2[i])
			return (new1[i] - new2[i]);
		i++;
	}
	return (0);
}
