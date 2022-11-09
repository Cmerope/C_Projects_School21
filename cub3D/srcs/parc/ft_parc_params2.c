/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parc_params2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:11:34 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 18:11:36 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	write_no(char *line, t_info *map_parser)
{
	char	*no_spec;

	map_parser->error = check_space(line, 'N');
	no_spec = ft_strchr(line, 'N');
	no_spec++;
	if (*no_spec == 'O')
	{
		map_parser->error = check_space(++no_spec, '.');
		check_texture(no_spec, map_parser);
		if (map_parser->error == 0)
			map_parser->no_path = ft_strchr(no_spec, '.');
	}
	else
		map_parser->error = -4;
}

void	write_we(char *line, t_info *map_parser)
{
	char	*we_spec;

	map_parser->error = check_space(line, 'W');
	we_spec = ft_strchr(line, 'W');
	we_spec++;
	if (*we_spec == 'E')
	{
		map_parser->error = check_space(++we_spec, '.');
		check_texture(we_spec, map_parser);
		if (map_parser->error == 0)
			map_parser->we_path = ft_strchr(we_spec, '.');
	}
	else
		map_parser->error = -4;
}

void	write_ea(char *line, t_info *map_parser)
{
	char	*ea_spec;

	map_parser->error = check_space(line, 'E');
	ea_spec = ft_strchr(line, 'E');
	ea_spec++;
	if (*ea_spec == 'A')
	{
		map_parser->error = check_space(++ea_spec, '.');
		check_texture(ea_spec, map_parser);
		if (map_parser->error == 0)
			map_parser->ea_path = ft_strchr(ea_spec, '.');
	}
	else
		map_parser->error = -4;
}

void	write_sprites(t_info *map_parser, char *line)
{
	map_parser->error = check_space(line, '.');
	check_texture(line, map_parser);
	if (map_parser->error == 0)
		map_parser->s_path = ft_strchr(line, '.');
}

void	write_s(char *line, t_info *map_parser)
{
	char	*s_spec;
	int		flag_so;
	int		flag_s;

	flag_so = 0;
	flag_s = 0;
	map_parser->error = check_space(line, 'S');
	s_spec = ft_strchr(line, 'S');
	s_spec++;
	if (*s_spec == 'O')
	{
		flag_so = 1;
		map_parser->error = check_space(++s_spec, '.');
		check_texture(s_spec, map_parser);
		if (map_parser->error == 0)
			map_parser->so_path = ft_strchr(s_spec, '.');
	}
	else if (*s_spec != 'O')
	{
		flag_s = 1;
		write_sprites(map_parser, s_spec);
	}
	else if (flag_so == 0 && flag_s == 0)
		map_parser->error = -4;
}
