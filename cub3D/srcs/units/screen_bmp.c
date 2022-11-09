/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <cmerope@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 22:34:50 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 18:13:57 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	*bmp_header(t_info *info)
{
	static char		bmp[54];

	bmp[0] = 'B';
	bmp[1] = 'M';
	*((int *)(bmp + 2)) = info->width * info->height * 4 + 54;
	*(int *)(bmp + 10) = 54;
	*(int *)(bmp + 14) = 40;
	*(int *)(bmp + 18) = (int)info->width;
	*(int *)(bmp + 22) = (int)info->height;
	*(bmp + 26) = 1;
	*(bmp + 28) = 32;
	return ((void *)bmp);
}

void	write_img(int fd, t_info *info)
{
	unsigned int	color;
	int				y;
	int				x;

	y = info->height - 1;
	while (y > 0)
	{
		x = 0;
		while (x < info->width)
		{
			color = info->buf[y][x];
			write(fd, &color, 4);
			x++;
		}
		y--;
	}
}

int	create_clean_file(const char *name)
{
	int		fd;

	fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0)
		perror("ERROR: can't creat screenshot\n");
	return (fd);
}

void	ft_creat_screen_bmp(t_info *info)
{
	int		fd;
	void	*bmp;

	fd = create_clean_file("screenshot.bmp");
	if (fd < 0)
		exit(1);
	bmp = bmp_header(info);
	write(fd, bmp, 54);
	math_raycast(info);
	keyboard(info);
	write_img(fd, info);
}
