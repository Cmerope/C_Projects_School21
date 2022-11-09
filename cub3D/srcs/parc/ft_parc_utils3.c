/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parc_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:12:12 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 18:12:15 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	chek_map_coner(char **array_map, t_info *info, int j, int i)
{
	if (j == 0 && i == 0)
		info->error = chek_coner_left(array_map, info, j, i);
	else if (j == (info->count_lines - 1) && i == 0)
		info->error = chek_coner_left(array_map, info, j, i);
	else if (j == (info->count_lines - 1) && array_map[j][i + 1] == '\0')
		info->error = chek_coner_right(array_map, info, j, i);
	else if (j == 0 && array_map[j][i + 1] == '\0')
		info->error = chek_coner_right(array_map, info, j, i);
	return (info->error);
}

int	chek_map_perimetr(char **array_map, t_info *info, int j, int i)
{
	if (j == 0 || j == (info->count_lines - 1))
		info->error = chek_perimetr_j(array_map, info, j, i);
	if (i == 0 || array_map[j][i + 1] == '\0')
		info->error = chek_perimetr_i(array_map, j, i);
	return (info->error);
}

int	chek_map_space(char **array_map, t_info *info, int j, int i)
{
	if (array_map[j][i] == '1')
		return (1);
	else if (ft_chek_null(array_map, j, i + 1) == 0)
		return (-1);
	else if (array_map[j][i] == ' ')
	{
		info->error = chek_map_coner(array_map, info, j, i);
		if (info->error == 1)
			info->error = chek_map_perimetr(array_map, info, j, i);
	}
	if (info->error != 1 && info->error < 1)
		close_wind();
	return (0);
}

void	chek_perimetr(char **array_map, t_info *info, int j, int i)
{
	j = 0;
	while (array_map[j])
	{
		i = 0;
		while (array_map[j][i])
		{
			if (j == 0 || i == 0 || (array_map[j][i + 1] == '\0')
					|| (j == (info->count_lines - 1)))
			{
				info->error = chek_map_space(array_map, info, j, i);
				if (info->error != 1)
				{
					info->error = chek_map_coner(array_map, info, j, i);
					if (info->error != -1)
					{
						info->error = chek_map_perimetr(array_map, info, j, i);
					}
				}
			}
			else
				info->error = chek_valid_sim(array_map, info, j, i);
			i++;
		}
		j++;
	}
}
