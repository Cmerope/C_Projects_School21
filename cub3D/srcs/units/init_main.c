/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:13:40 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 18:13:43 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_main(t_info *info)
{
	init_window(info);
	init_raycast(info);
	init_parc(info);
	init_keyboard(info);
}

void	init_window(t_info *info)
{
	info->flag_save = 0;
	info->flag_map = 0;
	info->mlx = NULL;
	info->win = NULL;
	info->error = 0;
	info->sqw_height = 64;
	info->sqw_width = 64;
	info->array_map = NULL;
	info->count_lines = 0;
}

void	init_raycast(t_info *info)
{
	info->pos_x = 0.0;
	info->pos_y = 0.0;
	info->move = 0.05;
	info->rot = 0.05;
	info->kompas = 0 ;
}

void	init_parc(t_info *info)
{
	info->width = -1;
	info->height = -1;
	info->position = 0;
	info->floor_r = -1;
	info->floor_g = -1;
	info->floor_b = -1;
	info->ceilling_r = -1;
	info->ceilling_g = -1;
	info->ceilling_b = -1;
	info->no_path = 0;
	info->we_path = 0;
	info->ea_path = 0;
	info->so_path = 0;
	info->s_path = 0;
}

void	init_keyboard(t_info *info)
{
	info->key_a = 0;
	info->key_w = 0;
	info->key_s = 0;
	info->key_d = 0;
	info->key_la = 0;
	info->key_ra = 0;
}
