/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:20:44 by cmerope           #+#    #+#             */
/*   Updated: 2020/11/23 13:39:56 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					m;
	unsigned long int	res;

	while (*str == ' ' || *str == '\t' || *str == '\n' ||
			*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	m = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			m = (-1);
		str++;
	}
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if ((res > 9223372036854775807) && m == (-1))
			return (0);
		if (res > 9223372036854775807)
			return (-1);
		str++;
	}
	return (res * m);
}
