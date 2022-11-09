/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:28:43 by cmerope           #+#    #+#             */
/*   Updated: 2020/11/14 15:41:06 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*buff;
	unsigned int	num;

	num = size * count;
	buff = (void*)malloc(num);
	if (buff)
		ft_memset(buff, 0, num);
	return (buff);
}
