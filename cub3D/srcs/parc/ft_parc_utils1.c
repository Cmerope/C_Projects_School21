/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parc_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:11:43 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 18:11:46 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == 0)
		return ;
	write(fd, s, ft_strlen(s));
}

void	ft_chek_kompas(t_info *all_struct, char *new_line)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (new_line[i] != '\0')
	{
		if (new_line[i] == 'N' || new_line[i] == 'E'
			|| new_line[i] == 'W' || new_line[i] == 'S')
			j++;
		i++;
	}
	if (j != 1)
	{
		all_struct->error = -3;
		close_wind();
	}
}

int	check_space(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i] != c)
	{
		if (line[i] != ' ' && line[i] != '\t')
		{
			ft_exit();
		}
		i++;
	}
	return (0);
}
