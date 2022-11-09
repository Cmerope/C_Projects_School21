/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:18:04 by cmerope           #+#    #+#             */
/*   Updated: 2020/11/23 21:03:25 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*new;
	unsigned char	*new2;

	new = (unsigned char*)dst;
	new2 = (unsigned char*)src;
	if (dst == 0 && src == 0)
		return (0);
	if (new > new2)
	{
		while (n && *new2)
		{
			new[n - 1] = new2[n - 1];
			n--;
		}
	}
	if (new < new2)
		ft_memcpy(new, new2, n);
	return (dst);
}
