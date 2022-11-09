/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:13:29 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 18:13:33 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_buf(t_info *info)
{
	buf_for_draw(info);
	buf_for_tex(info);
	buf_for_z(info);
}

static void	buf_full(t_info *info, int i, int j, int type)
{
	if (type == 1)
	{
		i = 0;
		while (i < info->height)
		{
			j = 0;
			while (j++ < info->width)
				info->buf[i][j] = 0;
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < 5)
		{
			j = 0;
			while (j++ < info->sqw_height * info->sqw_width)
				info->texture[i][j] = 0;
			i++;
		}
	}
}

int	buf_for_draw(t_info *info)
{
	int	i;
	int	j;

	j = 0;
	info->buf = (int **)malloc(sizeof(int *) * info->height);
	if (!info->buf)
		return (-1);
	i = 0;
	while (i < info->height)
	{
		info->buf[i] = (int *)malloc(sizeof(int) * info->width);
		if (!info->buf[i])
			return (-1);
		i++;
	}
	buf_full(info, 0, 0, 1);
	return (0);
}

int	buf_for_tex(t_info *info)
{
	int	i;
	int	j;

	j = 0;
	info->texture = (int **)malloc(sizeof(int *) * 5);
	if (!info->texture)
		return (-1);
	i = 0;
	while (i < 5)
	{
		info->texture[i] = (int *)malloc(sizeof(int)
				* (info->sqw_height * info->sqw_width));
		if (!info->texture[i])
			return (-1);
		i++;
	}
	buf_full(info, 0, 0, 0);
	return (0);
}

int	buf_for_z(t_info *info)
{
	int	i;

	info->zBuffer = (double *)malloc(sizeof(double) * (info->width));
	if (!info->zBuffer)
		return (-1);
	i = 0;
	while (i < info->width)
	{
		info->zBuffer[i] = 0;
		i++;
	}
	return (0);
}
