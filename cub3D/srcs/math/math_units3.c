/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_units3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:10:48 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 18:10:51 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calk_sprite_texX(int *stripe, t_info *info, t_calc *calc)
{
	calc->texX = (int)((256 * (*stripe - (-calc->spriteWidth / 2
						+ calc->spriteScreenX)) * info->sqw_width
				/ calc->spriteWidth) / 256);
}

void	draw_sprite(int *stripe, t_info *info, t_calc *calc)
{
	int	y;

	y = 0;
	while (*stripe < calc->drawEndX)
	{
		calk_sprite_texX(stripe, info, calc);
		if (calc->transformY > 0 && *stripe > 0 && *stripe < info->width
			&& calc->transformY < info->zBuffer[*stripe])
		{
			y = calc->drawStartY;
			while (y < calc->drawEndY)
			{
				calc->d = (y - calc->vMoveScreen) * 256 - info->height
					* 128 + calc->spriteHeight * 128;
				calc->texY = ((calc->d * info->sqw_height)
						/ calc->spriteHeight) / 256;
				calc->color = info->texture[4][info->sqw_width
					* calc->texY + calc->texX];
				if ((calc->color & 0xFFFFFF) != 0)
					info->buf[y][*stripe] = calc->color;
				y++;
			}
		}
		*stripe += 1;
	}
}

void	calc_start_sprite_draw_variables(t_info *info, t_calc *calc,
		int *stripe)
{
	if (calc->drawStartY < 0)
		calc->drawStartY = 0;
	calc->drawEndY = calc->spriteHeight / 2 + info->height / 2
		+ calc->vMoveScreen;
	if (calc->drawEndY >= info->height)
		calc->drawEndY = info->height - 1;
	calc->spriteWidth = (int)fabs((info->height / calc->transformY) / 1);
	calc->drawStartX = -calc->spriteWidth / 2 + calc->spriteScreenX;
	if (calc->drawStartX < 0)
		calc->drawStartX = 0;
	calc->drawEndX = calc->spriteWidth / 2 + calc->spriteScreenX;
	if (calc->drawEndX >= info->width)
		calc->drawEndX = info->width - 1;
	*stripe = calc->drawStartX;
}

void	prepare_sprite_variables(t_info *info, t_calc *calc)
{
	calc->invDet = 1.0 / (info->plane_x * info->dir_y - info->dir_x
			* info->plane_y);
	calc->transformX = calc->invDet * (info->dir_y * calc->spriteX
			- info->dir_x * calc->spriteY);
	calc->transformY = calc->invDet * (-info->plane_y * calc->spriteX
			+ info->plane_x * calc->spriteY);
	calc->spriteScreenX = (int)((info->width / 2) * (1 + calc->transformX
				/ calc->transformY));
	calc->vMoveScreen = 0;
	calc->spriteHeight = (int)fabs((info->height / calc->transformY) / 1);
	calc->drawStartY = -calc->spriteHeight / 2 + info->height / 2
		+ calc->vMoveScreen;
}

void	sprite_calc_and_make(t_info *info, t_calc *calc, int *spriteOrder)
{
	int	stripe;
	int	i;

	i = 0;
	while (i < info->numSprites)
	{
		calc->spriteX = info->sprite[spriteOrder[i]][0] - info->pos_x;
		calc->spriteY = info->sprite[spriteOrder[i]][1] - info->pos_y;
		prepare_sprite_variables(info, calc);
		calc_start_sprite_draw_variables(info, calc, &stripe);
		draw_sprite(&stripe, info, calc);
		i++;
	}
}
