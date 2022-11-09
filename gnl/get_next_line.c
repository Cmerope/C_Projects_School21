/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <cmerope@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:17:55 by cmerope           #+#    #+#             */
/*   Updated: 2020/12/29 11:16:10 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	int			i;
	int			j;

	if (!s1 && !s2)
		return (0);
	str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char			*join_static_arr(char **static_arr, char *tmp_buff)
{
	char		*pointer;

	if (*static_arr == NULL)
	{
		*static_arr = malloc(sizeof(char*) * 1);
		if (!*static_arr)
			return (NULL);
		*static_arr[0] = '\0';
	}
	pointer = *static_arr;
	*static_arr = ft_strjoin(pointer, tmp_buff);
	if (!static_arr)
	{
		free(tmp_buff);
		free(pointer);
		return (NULL);
	}
	free(pointer);
	return (*static_arr);
}

int				clean(char *buff)
{
	if (buff)
		free(buff);
	buff = NULL;
	return (0);
}

int				get_next_line(int fd, char **line)
{
	int			read_bit;
	char		*buff;
	static char	*static_arr;

	while (line && BUFFER_SIZE > 0 && fd >= 0 && (read_bit = read(fd,
	(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))), BUFFER_SIZE)) >= 0)
	{
		buff[read_bit] = '\0';
		static_arr = join_static_arr(&static_arr, buff);
		if ((ft_strchr(static_arr, '\n')))
		{
			if ((static_arr = copy_and_save(&static_arr, &*line)))
				return (clean(buff) + 1);
		}
		else if ((read_bit == 0) && (ft_strchr(static_arr, '\0')))
		{
			if ((static_arr = copy_and_save(&static_arr, &*line)))
			{
				static_arr = NULL;
				return (clean(buff));
			}
		}
		clean(buff);
	}
	return ((!line || BUFFER_SIZE <= 0 || fd < 0) ? -1 : clean(buff) - 1);
}
