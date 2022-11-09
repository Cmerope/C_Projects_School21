/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parc_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:12:22 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 18:12:24 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_chek_null(char **array_map, int j, int i)
{
	if (array_map[j] == NULL)
		close_wind();
	else if ((array_map[j][i] == '0' || array_map[j][i] == '2')
			|| (array_map[j][i] == 'N' || array_map[j][i] == 'E'
				|| array_map[j][i] == 'W' || array_map[j][i] == 'S'))
		return (0);
	return (-1);
}

int	chek_coner_left(char **array_map, t_info *info, int j, int i)
{
	if (j == 0 && i == 0)
	{
		if (ft_chek_null(array_map, j + 1, i) == 0)
			close_wind();
		if (ft_chek_null(array_map, j, i + 1) == 0)
			close_wind();
	}
	else if (j == (info->count_lines - 1) && i == 0)
	{
		if (ft_chek_null(array_map, j - 1, i) == 0)
			close_wind();
		if (ft_chek_null(array_map, j, i + 1) == 0)
			close_wind();
	}
	return (0);
}

int	chek_coner_right(char **array_map, t_info *info, int j, int i)
{
	if (j == (info->count_lines - 1) && array_map[j][i + 1] == '\0')
	{
		if (ft_chek_null(array_map, j - 1, i) == 0)
			close_wind();
		if (ft_chek_null(array_map, j, i - 1) == 0)
			close_wind();
	}
	else if (j == 0 && array_map[j][i + 1] == '\0')
	{
		if (ft_chek_null(array_map, j - 1, i) == 0)
			close_wind();
		if (ft_chek_null(array_map, j, i + 1) == 0)
			close_wind();
	}
	return (0);
}

int	chek_perimetr_j(char **array_map, t_info *info, int j, int i)
{
	if (j == 0)
	{
		if (ft_chek_null(array_map, j + 1, i) == 0)
			close_wind();
	}
	if (j == (info->count_lines - 1))
	{
		if (ft_chek_null(array_map, j - 1, i) == 0)
			close_wind();
	}
	if (ft_chek_null(array_map, j, i + 1) == 0)
		close_wind();
	if (ft_chek_null(array_map, j, i - 1) == 0)
		close_wind();
	return (0);
}

int	chek_perimetr_i(char **array_map, int j, int i)
{
	if (i == 0)
	{
		if (ft_chek_null(array_map, j, i + 1) == 0)
			close_wind();
	}
	if (array_map[j][i + 1] == '\0')
	{
		if (ft_chek_null(array_map, j, i - 1) == 0)
			close_wind();
	}
	if (ft_chek_null(array_map, j + 1, i) == 0)
		close_wind();
	if (ft_chek_null(array_map, j - 1, i) == 0)
		close_wind();
	return (0);
}
