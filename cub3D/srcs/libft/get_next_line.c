/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:10:00 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 18:10:03 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_next_line(int fd, char **line)
{
	int		rd;
	char	buf[2];

	rd = 0;
	*line = (char *)malloc(1);
	if (!line)
		ft_exit();
	*line[0] = '\0';
	rd = 1;
	while (rd != 0)
	{
		rd = read(fd, buf, 1);
		if (rd == -1)
			ft_exit();
		buf[rd] = '\0';
		if (buf[0] == '\n')
			return (1);
		*line = ft_strjoin(*line, buf);
	}
	return (0);
}
