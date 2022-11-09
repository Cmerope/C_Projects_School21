/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:07:58 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 18:08:00 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_argc(char *name, char *save)
{
	char	*tmp_name;
	int		result;

	result = 0;
	if (save != NULL)
	{
		result = ft_strncmp(save, "--save", 7);
		if (result == 0)
			return (1);
	}
	tmp_name = ft_strchr(name, '.');
	if (tmp_name != NULL)
	{
		result = ft_strncmp(tmp_name, ".cub", 5);
		if (result == 0)
			return (1);
	}
	return (0);
}

static int	check_error (t_info *info)
{
	if (info->error != 0)
	{
		if (info->error == -1)
			perror("ERROR\nNot valid perimetr\n");
		if (info->error == -2)
			perror("ERROR\nNot valid map\n");
		if (info->error == -3)
			perror("ERROR\nNot valid komps\n");
		if (info->error == -4)
			perror("ERROR\nNot valid params\n");
		if (info->error == -5)
			perror("ERROR\nMemmory crash\n");
		if (info->error == -6)
			perror("ERROR\nProblems with argc\n");
		return (-1);
	}
	return (0);
}

void	ft_exit(void)
{
	printf("ERROR\n");
	exit(-1);
}

static int	start(t_info *info, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("ERROR\nFile 11111is not available");
		exit(-1);
	}
	info->array_map = ft_parc(fd, info);
	if ((close(fd)) == -1)
	{
		perror("ERROR\nFile is!!!! not available ");
		exit(-1);
	}
	info->mlx = mlx_init();
	init_start(info);
	if (info->flag_save == 0)
		mlx_loop(info->mlx);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_info	info;
	int		error;

	if (argc == 3 || argc == 2)
	{
		init_main(&info);
		if (argc == 3)
		{
			if (check_argc(argv[1], argv[2]) == 1)
				info.flag_save = 1;
		}
		else
		{
			if (check_argc(argv[1], NULL) == 1)
				info.flag_save = 0;
		}
		start(&info, argv);
	}
	else
		close_wind();
	error = check_error(&info);
	if (check_error(&info) == -1)
		close_wind();
	ft_creat_screen_bmp(&info);
}
