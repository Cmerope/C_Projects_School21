/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:14:19 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 18:14:21 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	where_player(t_info *info)
{
	int	i;
	int	j;

	j = 0;
	while (info->array_map[j] != '\0')
	{
		i = 0;
		while (info->array_map[j][i] != '\0')
		{
			if (info->array_map[j][i] == 'N' || info->array_map[j][i] == 'W' ||
				info->array_map[j][i] == 'S' || info->array_map[j][i] == 'E')
			{
				info->kompas = info->array_map[j][i];
				init_where_player(info);
				info->pos_x = j + 0.5;
				info->pos_y = i + 0.5;
				info->array_map[j][i] = '0';
				break ;
			}
			i++;
		}
		if (info->pos_x != 0 && info->pos_y != 0)
			break ;
		j++;
	}
}

void	init_where_player(t_info *info)
{
	if (info->kompas == 'E' || info->kompas == 'W')
	{
		info->dir_x = 0;
		info->dir_y = 1;
		info->plane_x = 0.66;
		info->plane_y = 0;
		if (info->kompas == 'W')
		{
			info->dir_y = -1;
			info->plane_x = -0.66;
		}
	}
	else if (info->kompas == 'N' || info->kompas == 'S')
	{
		info->dir_x = -1;
		info->dir_y = 0;
		info->plane_x = 0;
		info->plane_y = 0.66;
		if (info->kompas == 'S')
		{
			info->dir_x = 1;
			info->plane_y = -0.66;
		}
	}
}
