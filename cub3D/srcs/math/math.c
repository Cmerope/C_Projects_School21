/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:10:17 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 18:10:21 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	dda_calc(t_info *info, t_calc *calc)
{
	while (calc->hit == 0)
	{
		if (calc->sideDistX < calc->sideDistY)
		{
			calc->sideDistX += calc->deltaDistX;
			calc->mapX += calc->stepX;
			calc->side = 0;
		}
		else
		{
			calc->sideDistY += calc->deltaDistY;
			calc->mapY += calc->stepY;
			calc->side = 1;
		}
		if ((info->array_map[calc->mapX][calc->mapY] - '0') > 0)
			calc->hit = 1;
	}
}

void	math_raycast(t_info *info)
{
	int		*spriteOrder;
	double	*spriteDistance;
	t_calc	calc;

	spriteOrder = NULL;
	spriteDistance = NULL;
	prepare_color(info, &calc);
	wall_calk_and_make(info, &calc);
	if (info->numSprites > 0)
	{
		spriteOrder = (int *)malloc(sizeof(int) * info->numSprites);
		spriteDistance = (double *)malloc(sizeof(double) * info->numSprites);
		if (!spriteOrder || !spriteDistance)
			close_wind();
	}
	make_sprite_arrey(info, spriteOrder, spriteDistance);
	if (info->numSprites > 0)
		quicksort(spriteDistance, spriteOrder, 0, info->numSprites - 1);
	sprite_calc_and_make(info, &calc, spriteOrder);
	if (info->numSprites > 0)
	{
		free(spriteOrder);
		free(spriteDistance);
	}
}
