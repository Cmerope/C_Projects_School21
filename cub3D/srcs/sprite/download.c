/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   download.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:12:42 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 18:12:48 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	download_image(t_info *info, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	img->img = mlx_xpm_file_to_image(info->mlx, path,
			&img->img_width, &img->img_height);
	if (!img->img)
	{
		perror ("ERROR");
		exit (1);
	}
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->size_l, &img->endian);
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
			texture[64 * y + x] = img->data[64 * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	download_texture(t_info *info)
{
	t_img	img;

	download_image(info, info->texture[0], info->we_path, &img);
	download_image(info, info->texture[1], info->ea_path, &img);
	download_image(info, info->texture[2], info->so_path, &img);
	download_image(info, info->texture[3], info->no_path, &img);
	download_image(info, info->texture[4], info->s_path, &img);
}
