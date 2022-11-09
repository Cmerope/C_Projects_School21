/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <cmerope@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:43:31 by cmerope           #+#    #+#             */
/*   Updated: 2020/12/28 12:23:02 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strchr(const char *s, int c)
{
	char		*tmp;

	tmp = (char*)s;
	while (*tmp || c == '\0')
	{
		if (*tmp == (char)c)
			return (tmp);
		tmp++;
	}
	return (0);
}

size_t			ft_strlen(const char *str)
{
	size_t		len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char			*ft_strdup(const char *src)
{
	int			i;
	char		*buff;

	buff = malloc(sizeof(*buff) * (ft_strlen(src) + 1));
	if (!buff)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		buff[i] = src[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

char			*copy_line(char **static_arr, char **line)
{
	*line = ft_strdup(*static_arr);
	if (!*line)
	{
		free(*static_arr);
		return (NULL);
	}
	return (*line);
}

char			*copy_and_save(char **static_arr, char **line)
{
	char		*pointer;
	char		*tmp_static_arr;

	if ((pointer = ft_strchr(*static_arr, '\n')))
	{
		*pointer = '\0';
		if (!(*line = copy_line(static_arr, line)))
			return (NULL);
		tmp_static_arr = *static_arr;
		if (!(*static_arr = ft_strdup(++pointer)))
		{
			free(tmp_static_arr);
			free(*line);
			return (NULL);
		}
		free(tmp_static_arr);
	}
	else if ((pointer = ft_strchr(*static_arr, '\0')))
	{
		if (!(*line = copy_line(static_arr, line)))
			return (NULL);
		free(*static_arr);
	}
	return (*static_arr);
}
