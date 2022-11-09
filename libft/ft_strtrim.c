/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:30:57 by cmerope           #+#    #+#             */
/*   Updated: 2020/11/20 15:04:40 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_true(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_start(char const *s1, char const *s2)
{
	size_t	len;

	len = 0;
	while (s1[len] != '\0' && ft_true(s2, s1[len]))
		len++;
	return (len);
}

static int	ft_end(char const *s1, char const *s2, size_t start)
{
	size_t	len;

	len = ft_strlen(s1);
	while (len >= start && ft_true(s2, s1[len - 1]))
		len--;
	return (len);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	if (s1 == 0)
		return (0);
	start = ft_start(s1, set);
	if (start == ft_strlen(s1))
	{
		if (!(str = (char*)malloc(sizeof(*s1) * 1)))
			return (NULL);
		*str = '\0';
	}
	else
	{
		end = ft_end(s1, set, start);
		if (!(str = (char*)malloc(sizeof(*s1) * (end - start + 1))))
			return (NULL);
		i = 0;
		while (start < end)
			str[i++] = s1[start++];
		str[i] = '\0';
	}
	return (str);
}
