/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:29:16 by cmerope           #+#    #+#             */
/*   Updated: 2020/11/25 17:30:06 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			len_w;
	char			*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= (size_t)start)
	{
		if (!(str = malloc(sizeof(char) * 1)))
			return (NULL);
		*str = '\0';
		return (str);
	}
	len_w = (ft_strlen(s) - (size_t)start) < len ?
			(ft_strlen(s) - (size_t)start) : len;
	if (!(str = malloc(sizeof(char) * (len_w + 1))))
		return (NULL);
	i = 0;
	while (i < len_w && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
