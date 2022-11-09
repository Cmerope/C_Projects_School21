/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <cmerope@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:15:55 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 13:43:51 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned char	*s3;
	unsigned char	*s4;

	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	while ((*s3 != '\0' || *s4 != '\0') && n > 0)
	{
		if (*s3 == *s4)
		{
			s3++;
			s4++;
			n--;
		}
		else
			return (*s3 - *s4);
	}
	return (0);
}
