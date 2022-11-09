/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:11:08 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 18:11:11 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_int(t_info *info)
{
	if (info->floor_r == -1 || info->width == -1
		|| info->height == -1 || info->floor_g == -1
		|| info->floor_b == -1 || info->ceilling_r == -1
		|| info->ceilling_g == -1 || info->ceilling_b == -1
		|| info->no_path == 0 || info->we_path == 0
		|| info->ea_path == 0 || info->so_path == 0
		|| info->s_path == 0)
		return (0);
	return (1);
}

void	ft_chek_params(t_info *info, char *line)
{
	if (ft_strchr(line, 'R'))
		write_resolution(line, info);
	else if (ft_strchr(line, 'F'))
		write_floor(line, info);
	else if (ft_strchr(line, 'C'))
		write_ceilling(line, info);
	else if (ft_strchr(line, 'N'))
		write_no(line, info);
	else if (ft_strchr(line, 'W'))
		write_we(line, info);
	else if (ft_strchr(line, 'E'))
		write_ea(line, info);
	else if (ft_strchr(line, 'S'))
		write_s(line, info);
	if (ft_check_int(info) == 1)
		check_value_rgb(info);
}

void	join_map_line(t_parc *parc, t_info *info)
{
	info->count_lines++;
	parc->new_line = ft_strjoin(parc->new_line, parc->line);
	parc->new_line = ft_strjoin(parc->new_line, parc->seporstor);
	free(parc->line);
}

void	read_line(int fd, t_parc *parc, t_info *info)
{
	while (get_next_line(fd, &parc->line) > 0)
	{
		if (ft_strchr(parc->new_line, '1'))
		{
			if (*parc->line == 0)
				close_wind();
		}
		if ((ft_check_int(info) == 1) && ft_strchr(parc->line, '1'))
			join_map_line(parc, info);
		else if (ft_check_int(info) != 1)
			ft_chek_params(info, parc->line);
		else if (ft_check_int(info) == 1)
		{
			check_space(parc->line, '\0');
			free(parc->line);
		}
		else
			free(parc->line);
	}
	parc->new_line = ft_strjoin(parc->new_line, parc->line);
	parc->new_line = ft_strjoin(parc->new_line, parc->seporstor);
}

char	**ft_parc(int fd, t_info *info)
{
	t_parc	parc;
	char	**array_map;

	parc.new_line = (char *)malloc(1);
	parc.new_line[0] = '\0';
	if (!parc.new_line)
		close_wind();
	parc.seporstor = (char *)malloc(2);
	if (!parc.seporstor)
	{
		free (parc.new_line);
		close_wind();
	}
	parc.seporstor[0] = '\n';
	parc.seporstor[1] = '\0';
	read_line(fd, &parc, info);
	ft_chek_kompas(info, parc.new_line);
	array_map = ft_split(parc.new_line, '\n');
	chek_perimetr(array_map, info, 0, 0);
	if (info->error < 0)
		close_wind();
	free(parc.line);
	free(parc.new_line);
	free(parc.seporstor);
	return (array_map);
}
