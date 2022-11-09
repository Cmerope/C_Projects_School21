/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <cmerope@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:09:33 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 18:09:02 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strchr(char *s, int c)
{
	char	*tmp;

	tmp = (char *)s;
	while (*tmp || c == '\0')
	{
		if (*tmp == (char)c)
			return (tmp);
		tmp++;
	}
	return (0);
}
