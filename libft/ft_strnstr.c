/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <cmerope@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:39:20 by cmerope           #+#    #+#             */
/*   Updated: 2020/11/26 18:43:46 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;

	if ((!*to_find) || (!*to_find && !*str))
		return ((char*)str);
	if (len == 0 || !*str)
		return (0);
	while (*str && len > 0)
	{
		i = 0;
		while (to_find[i] != '\0' && i < len)
		{
			if (to_find[i] != str[i])
				break ;
			i++;
		}
		if (to_find[i] == '\0' || !*to_find)
			return ((char*)str);
		str++;
		len--;
	}
	return (0);
}
