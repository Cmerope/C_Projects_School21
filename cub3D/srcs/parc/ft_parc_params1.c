/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parc_params1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:11:25 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 18:11:27 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_value_rgb(t_info *map_parser)
{
	if (map_parser->floor_r < 0 || map_parser->floor_r > 255)
		map_parser->error = -4;
	if (map_parser->floor_g < 0 || map_parser->floor_g > 255)
		map_parser->error = -4;
	if (map_parser->floor_b < 0 || map_parser->floor_b > 255)
		map_parser->error = -4;
	if (map_parser->ceilling_r < 0 || map_parser->ceilling_r > 255)
		map_parser->error = -4;
	if (map_parser->ceilling_g < 0 || map_parser->ceilling_g > 255)
		map_parser->error = -4;
	if (map_parser->ceilling_b < 0 || map_parser->ceilling_b > 255)
		map_parser->error = -4;
	if (map_parser->error == -4)
		close_wind();
}

void	write_resolution(char *line, t_info *map_parser)
{
	int		max_size_x;
	int		max_size_y;
	char	*r_spec;

	mlx_get_screen_size(&max_size_x, &max_size_y);
	map_parser->error = check_space(line, 'R');
	r_spec = ft_strchr(line, 'R');
	r_spec++;
	map_parser->width = ft_atoi_par(r_spec, map_parser, 10);
	if (map_parser->width > max_size_x)
		map_parser->width = max_size_x;
	map_parser->height = ft_atoi_par(map_parser->position, map_parser, 10);
	if (map_parser->height > max_size_y)
		map_parser->height = max_size_y;
	map_parser->error = check_space(map_parser->position, '\0');
	free(line);
}

void	write_floor(char *line, t_info *map_parser)
{
	char	*f_spec;

	map_parser->error = check_space(line, 'F');
	f_spec = ft_strchr(line, 'F');
	map_parser->floor_r = ft_atoi_par(++f_spec, map_parser, 10);
	map_parser->error = check_space(map_parser->position, ',');
	f_spec = ft_strchr(map_parser->position, ',');
	map_parser->floor_g = ft_atoi_par(++f_spec, map_parser, 10);
	map_parser->error = check_space(map_parser->position, ',');
	f_spec = ft_strchr(f_spec, ',');
	map_parser->floor_b = ft_atoi_par(++f_spec, map_parser, 10);
	map_parser->error = check_space(map_parser->position, '\0');
	free(line);
}

void	write_ceilling(char *line, t_info *map_parser)
{
	char	*c_spec;

	map_parser->error = check_space(line, 'C');
	c_spec = ft_strchr(line, 'C');
	map_parser->ceilling_r = ft_atoi_par(++c_spec, map_parser, 10);
	map_parser->error = check_space(map_parser->position, ',');
	c_spec = ft_strchr(line, ',');
	map_parser->ceilling_g = ft_atoi_par(++c_spec, map_parser, 10);
	map_parser->error = check_space(map_parser->position, ',');
	c_spec = ft_strchr(map_parser->position, ',');
	map_parser->ceilling_b = ft_atoi_par(++c_spec, map_parser, 10);
	map_parser->error = check_space(map_parser->position, '\0');
	free(line);
}
