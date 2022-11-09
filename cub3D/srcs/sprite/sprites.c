/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:13:08 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 18:13:10 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// считаем сколько спрайтов
static void	ft_cnt_sprites(t_info *info)
{
	int	i;
	int	j;

	j = 0;
	while (info->array_map[j] != '\0')
	{
		i = 0;
		while (info->array_map[j][i] != '\0')
		{
			if (info->array_map[j][i] == '2')
				info->numSprites++;
			i++;
		}
		j++;
	}
}

//  запись в массив спрайтов
static int	ft_mas_check(t_info *info, int c)
{
	int	i;
	int	j;

	j = 0;
	while (info->array_map[j] != '\0')
	{
		i = 0;
		while (info->array_map[j][i] != '\0')
		{
			if (info->array_map[j][i] == '2')
			{
				info->sprite[c][0] = j + 0.5;
				info->sprite[c][1] = i + 0.5;
				info->array_map[j][i] = '0';
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

//  выделение память под массив спрайтов и вызываешь заполнение массаива
int	ft_mas_sprites(t_info *info)
{
	int	c;

	c = 0;
	ft_cnt_sprites(info);
	info->sprite = (double **)malloc(sizeof(double *) * info->numSprites);
	if (!info->sprite)
		return (-1);
	while (c < info->numSprites)
	{
		info->sprite[c] = (double *)malloc(sizeof(double) * 2);
		if (!info->sprite[c])
			return (-1);
		c++;
	}
	c = 0;
	while (c < info->numSprites)
	{
		ft_mas_check(info, c);
		c++;
	}
	return (0);
}
