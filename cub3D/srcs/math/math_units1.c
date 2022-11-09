/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_units1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:10:27 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 18:10:30 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calc_start_draw_variables(t_info *info, t_calc *calc)
{
	calc->lineHeight = (int)(info->height / calc->perpWallDist);
	calc->drawStart = -calc->lineHeight / 2 + info->height / 2;
	calc->drawEnd = calc->lineHeight / 2 + info->height / 2;
	if (calc->drawStart < 0)
		calc->drawStart = 0;
	if (calc->drawEnd >= info->height)
		calc->drawEnd = info->height - 1;
	info->texNum = 0;
	if (calc->side == 0)
		calc->wallX = info->pos_y + calc->perpWallDist * calc->rayDirY;
	else
		calc->wallX = info->pos_x + calc->perpWallDist * calc->rayDirX;
	calc->wallX -= floor((calc->wallX));
	calc->texX = (int)(calc->wallX * (double)info->sqw_width);
	if (calc->side == 0 && calc->rayDirX > 0)
		calc->texX = info->sqw_width - calc->texX - 1;
	if (calc->side == 1 && calc->rayDirY < 0)
		calc->texX = info->sqw_width - calc->texX - 1;
	calc->step = 1.0 * info->sqw_width / calc->lineHeight;
	calc->texPos = (calc->drawStart - info->height / 2 + calc->lineHeight / 2)
		* calc->step;
}

void	calc_deist_to_wall(t_info *info, t_calc *calc)
{
	if (calc->side == 0)
		calc->perpWallDist = (calc->mapX - info->pos_x
				+ (1 - calc->stepX) / 2) / calc->rayDirX;
	else
		calc->perpWallDist = (calc->mapY - info->pos_y
				+ (1 - calc->stepY) / 2) / calc->rayDirY;
}

void	prepare_variables_for_dda_path_two(t_info *info, t_calc *calc)
{
	if (calc->rayDirX < 0)
	{
		calc->stepX = -1;
		calc->sideDistX = (info->pos_x - calc->mapX) * calc->deltaDistX;
	}
	else
	{
		calc->stepX = 1;
		calc->sideDistX = (calc->mapX + 1.0 - info->pos_x) * calc->deltaDistX;
	}
	if (calc->rayDirY < 0)
	{
		calc->stepY = -1;
		calc->sideDistY = (info->pos_y - calc->mapY) * calc->deltaDistY;
	}
	else
	{
		calc->stepY = 1;
		calc->sideDistY = (calc->mapY + 1.0 - info->pos_y) * calc->deltaDistY;
	}
}

void	prepare_variables_for_dda_path_one(t_info *info, t_calc *calc, int x)
{
	calc->cameraX = 2 * x / (double)info->width - 1;
	calc->rayDirX = info->dir_x + info->plane_x * calc->cameraX;
	calc->rayDirY = info->dir_y + info->plane_y * calc->cameraX;
	calc->mapX = (int)info->pos_x;
	calc->mapY = (int)info->pos_y;
	calc->deltaDistX = fabs(1 / calc->rayDirX);
	calc->deltaDistY = fabs(1 / calc->rayDirY);
	calc->hit = 0;
}

void	wall_calk_and_make(t_info *info, t_calc *calc)
{
	int	x;

	x = 0;
	while (x < info->width)
	{
		prepare_variables_for_dda_path_one(info, calc, x);
		prepare_variables_for_dda_path_two(info, calc);
		dda_calc(info, calc);
		calc_deist_to_wall(info, calc);
		calc_start_draw_variables(info, calc);
		prepare_wall_img(info, calc, x);
		x++;
	}
}
