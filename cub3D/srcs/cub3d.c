/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:07:43 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 18:07:49 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_img(t_info *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			info->img.data[y * info->width + x] = info->buf[y][x];
			x++;
		}
		y++;
	}
	if (info->flag_save == 0)
		mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

static int	key_press(int key, t_info *info)
{
	if (key == 53)
		exit(0);
	else if (key == 13)
		info->key_w = 1;
	else if (key == 0)
		info->key_a = 1;
	else if (key == 1)
		info->key_s = 1;
	else if (key == 2)
		info->key_d = 1;
	else if (key == 123)
		info->key_la = 1;
	else if (key == 124)
		info->key_ra = 1;
	return (0);
}

static int	key_release(int key, t_info *info)
{
	if (key == 53)
		exit(0);
	else if (key == 13)
		info->key_w = 0;
	else if (key == 0)
		info->key_a = 0;
	else if (key == 1)
		info->key_s = 0;
	else if (key == 2)
		info->key_d = 0;
	else if (key == 123)
		info->key_la = 0;
	else if (key == 124)
		info->key_ra = 0;
	return (0);
}

static int	main_loop(t_info *info)
{
	math_raycast(info);
	draw_img(info);
	keyboard(info);
	return (0);
}

void	init_start(t_info *info)
{
	info->win = mlx_new_window(info->mlx, info->width, info->height, "cub3D");
	info->img.img = mlx_new_image(info->mlx, info->width, info->height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, \
	&info->img.bpp, &info->img.size_l, &info->img.endian);
	where_player(info);
	init_buf(info);
	ft_mas_sprites(info);
	download_texture(info);
	mlx_loop_hook(info->mlx, &main_loop, info);
	if (info->flag_save == 0)
	{
		mlx_hook(info->win, 2, (1L << 0), &key_press, info);
		mlx_hook(info->win, 3, (1L << 0), &key_release, info);
		mlx_hook(info->win, 17, (1L << 0), &right_exit, info);
	}
}
