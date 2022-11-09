/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 09:03:21 by cmerope           #+#    #+#             */
/*   Updated: 2020/11/14 15:26:29 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*new;
	unsigned char	*new2;
	size_t			i;

	new = dst;
	new2 = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		new[i] = new2[i];
		if (new2[i] == (unsigned char)c)
			return (&dst[i + 1]);
		i++;
	}
	return (0);
}
