/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_count.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 01:34:01 by cmerope           #+#    #+#             */
/*   Updated: 2021/01/31 01:36:46 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t				ft_strlen(const char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int					ft_number_len(unsigned long len, int sys)
{
	int				i;
	unsigned long	sys_type;

	i = 0;
	if (sys == 1)
		sys_type = 10;
	if (sys == 0)
		sys_type = 16;
	while (len >= sys_type)
	{
		len /= sys_type;
		i++;
	}
	return (i + 1);
}

char				ft_putchar(char c)
{
	return (write(1, &c, 1));
}
