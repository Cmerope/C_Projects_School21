/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:14:08 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 18:14:10 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	key_w_s(t_info *info)
{
	double	x;
	double	y;
	char	**array;

	array = NULL;
	x = info->pos_x;
	y = info->pos_y;
	array = info->array_map;
	if (info->key_w)
	{
		if (!(array[(int)(x + 2 * info->dir_x * info->move)][(int)y] - '0'))
			info->pos_x += info->dir_x * info->move;
		if (!(array[(int)x][(int)(y + 2 * info->dir_y * info->move)] - '0'))
			info->pos_y += info->dir_y * info->move;
	}
	if (info->key_s)
	{
		if (!(array[(int)(x - 2 * info->dir_x * info->move)][(int)(y)] - '0'))
			info->pos_x -= info->dir_x * info->move;
		if (!(array[(int)(x)][(int)(y - 2 * info->dir_y * info->move)] - '0'))
			info->pos_y -= info->dir_y * info->move;
	}
}

void	key_a_d(t_info *info)
{
	double	x;
	double	y;
	char	**array;

	array = NULL;
	x = info->pos_x;
	y = info->pos_y;
	array = info->array_map;
	if (info->key_a)
	{
		if (!(array[(int)(x - 2 * info->dir_y * info->move)][(int)y] - '0'))
			info->pos_x -= info->dir_y * info->move;
		if (!(array[(int)x][(int)(y + 2 * info->dir_x * info->move)] - '0'))
			info->pos_y += info->dir_x * info->move;
	}
	if (info->key_d)
	{
		if (!(array[(int)(x + 2 * info->dir_y * info->move)][(int)y] - '0'))
			info->pos_x += info->dir_y * info->move;
		if (!(array[(int)x][(int)(y - 2 * info->dir_x * info->move)] - '0'))
			info->pos_y -= info->dir_x * info->move;
	}
}

void	key_ra_la(t_info *info)
{
	double	tmp1;
	double	tmp2;
	double	rot;

	tmp1 = info->dir_x;
	tmp2 = info->plane_x;
	rot = info->rot;
	if (info->key_ra)
	{
		info->dir_x = info->dir_x * cos(-rot) - info->dir_y * sin(-rot);
		info->dir_y = tmp1 * sin(-rot) + info->dir_y * cos(-rot);
		info->plane_x = info->plane_x * cos(-rot) - info->plane_y * sin(-rot);
		info->plane_y = tmp2 * sin(-rot) + info->plane_y * cos(-rot);
	}
	if (info->key_la)
	{
		info->dir_x = info->dir_x * cos(rot) - info->dir_y * sin(rot);
		info->dir_y = tmp1 * sin(rot) + info->dir_y * cos(rot);
		info->plane_x = info->plane_x * cos(rot) - info->plane_y * sin(rot);
		info->plane_y = tmp2 * sin(rot) + info->plane_y * cos(rot);
	}
}

void	keyboard(t_info *info)
{
	if (info->key_w || info->key_s)
		key_w_s(info);
	if (info->key_a || info->key_d)
		key_a_d(info);
	if (info->key_ra || info->key_la)
		key_ra_la(info);
}
