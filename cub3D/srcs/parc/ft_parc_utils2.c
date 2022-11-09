/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parc_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:11:53 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 18:11:54 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_atoi_par(char *str, t_info *map_parser, int base)
{
	unsigned long int	number;
	int					i;

	number = 0;
	i = 0;
	while (!(*str >= '0' && *str <= '9'))
	{
		if (*str == ' ' || *str == '\t' || *str == '\v'
			|| *str == '\f' || *str == '\r')
			str++;
		else
			ft_exit();
	}
	if (*str < '0' && *str >'9')
		ft_exit();
	while (*str >= '0' && *str <= '9')
	{
		number = number * base + (*str - '0');
		str++;
		i++;
	}
	map_parser->position = str;
	if (i > 5)
		return (10000);
	return (number);
}

void	check_texture(char *line, t_info *map_parser)
{
	char	*tmp_line;
	int		result;

	result = 0;
	tmp_line = ft_strchr(line, '.');
	tmp_line++;
	tmp_line = ft_strchr(tmp_line, '.');
	result = ft_strncmp(tmp_line, ".xpm", 4);
	if (result == 0)
	{
		while (*tmp_line != 'm')
			tmp_line++;
		map_parser->error = check_space(++tmp_line, '\0');
	}
	else
		close_wind();
}

int	chek_inside(char **array_map, int j, int i)
{
	if (ft_chek_null(array_map, j - 1, i) == 0 || array_map[j][i] == ' ')
		close_wind();
	if (ft_chek_null(array_map, j + 1, i) == 0 || array_map[j][i] == ' ')
		close_wind();
	if (ft_chek_null(array_map, j, i - 1) == 0 || array_map[j][i] == ' ')
		close_wind();
	if (ft_chek_null(array_map, j, i + 1) == 0 || array_map[j][i] == ' ')
		close_wind();
	return (0);
}

int	chek_valid_sim(char **array_map, t_info *map_parser, int j, int i)
{
	if (array_map[j][i] == '1' || ft_chek_null(array_map, j, i) == 0)
		return (map_parser->error);
	else if (array_map[j][i] == ' ')
	{
		if (chek_inside(array_map, j, i) == -2)
			close_wind();
	}
	else
		close_wind();
	return (0);
}
