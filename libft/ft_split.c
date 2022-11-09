/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:31:30 by cmerope           #+#    #+#             */
/*   Updated: 2020/11/21 22:04:50 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(const char *s, char separator)
{
	size_t		word_count;
	size_t		i;

	word_count = 0;
	i = 0;
	while (s[i] == separator && s[i])
		i++;
	while (s[i] != '\0')
	{
		if ((s[i] == separator && s[i + 1] != separator) || s[i + 1] == '\0')
			word_count += 1;
		i++;
	}
	return (word_count + 1);
}

static char		*ft_copy(char *massiv, const char *s, size_t start, size_t end)
{
	size_t			j;

	j = 0;
	while (start < end)
	{
		massiv[j] = s[start];
		j++;
		start++;
	}
	massiv[j] = '\0';
	return (massiv);
}

static void		ft_free_malloc(char **massiv, size_t line)
{
	size_t		i;

	i = 0;
	while (i < line)
	{
		free(massiv[i]);
		i++;
	}
	free(massiv);
}

static char		**ft_main(const char *s, char **massiv, char sep, size_t word)
{
	size_t		start;
	size_t		end;
	size_t		line;

	line = 0;
	start = 0;
	while (s[start] != '\0' && word - 1 > line)
	{
		while (s[start] == sep && s[start])
			start++;
		end = start;
		while (s[end] != sep && s[end])
			end++;
		if (!(massiv[line] = (char*)malloc(sizeof(char) * (end - start) + 1)))
		{
			ft_free_malloc(massiv, line);
			return (NULL);
		}
		ft_copy(massiv[line], s, start, end);
		line++;
		start = end;
	}
	massiv[line] = NULL;
	return (massiv);
}

char			**ft_split(char const *s, char c)
{
	char		**massiv;
	size_t		word_count;

	if (!s)
		return (NULL);
	word_count = ft_word_count(s, c);
	if (!(massiv = (char**)malloc(sizeof(char*) * word_count)))
		return (NULL);
	massiv = ft_main(s, massiv, c, word_count);
	return (massiv);
}
