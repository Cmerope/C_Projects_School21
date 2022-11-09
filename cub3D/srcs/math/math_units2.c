/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_units2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:10:35 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 18:10:38 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	make_sprite_arrey(t_info *info, int *spriteOrder,
		double *spriteDistance)
{
	int	i;

	i = 0;
	while (i < info->numSprites)
	{
		spriteOrder[i] = i;
		spriteDistance[i] = ((info->pos_x - info->sprite[i][0])
				* (info->pos_x - info->sprite[i][0]) + (info->pos_y
					- info->sprite[i][1]) * (info->pos_y - info->sprite[i][1]));
		i++;
	}
}

void	chose_wall_side_else(t_info *info, t_calc *calc, int *color)
{
	if (calc->rayDirY < 0)
	{
		info->texNum = 3;
		*color = info->texture[info->texNum][info->sqw_height
			* calc->texY + calc->texX];
	}
	else
	{
		info->texNum = 2;
		*color = info->texture[info->texNum][info->sqw_height
			* calc->texY + calc->texX];
	}
}

void	chose_wall_side(t_info *info, t_calc *calc, int *color)
{
	if (calc->side == 0)
	{
		if (calc->rayDirX < 0)
		{
			info->texNum = 1;
			*color = info->texture[info->texNum][info->sqw_height
				* calc->texY + calc->texX];
		}
		else
		{
			info->texNum = 0;
			*color = info->texture[info->texNum][info->sqw_height
				* calc->texY + calc->texX];
		}
	}
	else
		chose_wall_side_else(info, calc, color);
	if (calc->side == 0)
		*color = (*color >> 1) & 8355711;
}

void	prepare_wall_img(t_info *info, t_calc *calc, int x)
{
	int	color;
	int	y;

	y = calc->drawStart;
	while (y < calc->drawEnd)
	{
		calc->texY = (int)calc->texPos & (info->sqw_height - 1);
		calc->texPos += calc->step;
		chose_wall_side(info, calc, &color);
		info->buf[y][x] = color;
		y++;
	}
	info->zBuffer[x] = calc->perpWallDist;
}

void	prepare_color(t_info *info, t_calc *calc)
{
	int	x;
	int	y;

	y = info->height / 2;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			calc->color = info->floor_b;
			calc->color = calc->color | info->floor_g << 8;
			calc->color = calc->color | info->floor_r << 16;
			info->buf[y][x] = calc->color;
			calc->color = info->ceilling_b;
			calc->color = calc->color | info->ceilling_g << 8;
			calc->color = calc->color | info->ceilling_r << 16;
			info->buf[info->height - y - 1][x] = calc->color;
			x += 1;
		}
		y += 1;
	}
}
