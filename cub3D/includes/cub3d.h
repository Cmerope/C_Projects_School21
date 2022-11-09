/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:17:19 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 18:20:11 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "stdio.h"
# include "fcntl.h"
# include "math.h"
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 1

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_calc
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	double	wallX;
	int		texX;
	int		texY;
	double	step;
	double	texPos;
	double	spriteX;
	double	spriteY;
	double	invDet;
	double	transformX;
	double	transformY;
	int		spriteScreenX;
	int		vMoveScreen;
	int		spriteHeight;
	int		drawStartY;
	int		drawEndY;
	int		spriteWidth;
	int		drawStartX;
	int		drawEndX;
	int		stripe;
	int		d;
	int		color;
}				t_calc;

typedef struct s_info
{
	double	pos_x;
	double	pos_y;
	char	kompas;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move;
	double	rot;
	void	*mlx;
	void	*win;
	int		flag_save;
	int		flag_map;
	int		error;
	char	**array_map;
	int		count_lines;
	int		sqw_height;
	int		sqw_width;
	int		key_a;
	int		key_w;
	int		key_s;
	int		key_d;
	int		key_la;
	int		key_ra;
	t_img	img;
	int		floor_r;
	int		floor_g;
	int		floor_b;
	int		ceilling_r;
	int		ceilling_g;
	int		ceilling_b;
	char	*no_path;
	char	*we_path;
	char	*ea_path;
	char	*so_path;
	char	*s_path;
	char	*position;
	int		*max_size_x;
	int		*max_size_y;
	int		width;
	int		height;
	double	*zBuffer;
	double	**sprite;
	int		**buf;
	int		**texture;
	int		numSprites;
	int		texNum;
	char	start_pos;
}				t_info;

typedef struct s_pair
{
	double	first;
	int		second;
}				t_pair;

typedef struct s_sort
{
	int				i;
	int				j;
	double			middle_dist;
}				t_sort;

typedef struct s_parc
{
	char	*line;
	char	*new_line;
	char	*seporstor;
}				t_parc;

int		close_wind(void);
void	ft_exit(void);
int		right_exit(void);
void	where_player(t_info *info);
void	init_where_player(t_info *info);
void	init_buf(t_info *info);
int		buf_for_draw(t_info *info);
int		buf_for_tex(t_info *info);
int		buf_for_z(t_info *info);
void	init_start(t_info *info);
void	init_main(t_info *info);
void	init_window(t_info *info);
void	init_raycast(t_info *info);
void	init_parc(t_info *info);
void	init_keyboard(t_info *info);
int		ft_mas_sprites(t_info *info);
void	sortSprites(int *order, double *dist, int amount);
void	download_texture(t_info *info);
void	math_raycast(t_info *info);
void	dda_calc(t_info *info, t_calc *calc);
void	prepare_color(t_info *info, t_calc *calc);
void	wall_calk_and_make(t_info *info, t_calc *calc);
void	make_sprite_arrey(t_info *info, int *spriteOrder, \
		double *spriteDistance);
void	sprite_calc_and_make(t_info *info, t_calc *calc, int *spriteOrder);
void	prepare_wall_img(t_info *info, t_calc *calc, int x);
void	draw_img(t_info *info);
void	keyboard(t_info *info);
int		ft_strncmp(char *string1, char *string2, size_t num);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
size_t	ft_strlen(char *str);
int		get_next_line(int fd, char **line);
char	**ft_parc(int fd, t_info *info);
void	write_resolution(char *line, t_info *map_parser);
void	write_floor(char *line, t_info *map_parser);
void	write_ceilling(char *line, t_info *map_parser);
void	write_no(char *line, t_info *map_parser);
void	write_we(char *line, t_info *map_parser);
void	write_ea(char *line, t_info *map_parser);
void	write_s(char *line, t_info *map_parser);
void	write_write_sprites(char *line, t_info *map_parser);
int		ft_check_int(t_info *map_parser);
void	ft_putstr_fd(char *s, int fd);
void	ft_chek_params(t_info *all_struct, char *line);
void	ft_chek_kompas(t_info *all_struct, char *new_line);
int		ft_atoi_par(char *str, t_info *map_parser, int base);
int		check_space(char *line, char c);
void	check_texture(char *line, t_info *map_parser);
void	chek_perimetr(char **array_map, t_info *info, int i, int j);
int		ft_chek_null(char **array_map, int j, int i);
int		chek_coner_left(char **array_map, t_info *info, int j, int i);
int		chek_coner_right(char **array_map, t_info *info, int j, int i);
int		chek_perimetr_j(char **array_map, t_info *info, int i, int j);
int		chek_perimetr_i(char **array_map, int i, int j);
int		chek_inside(char **array_map, int j, int i);
int		chek_valid_sim(char **array_map, t_info *info, int j, int i);
void	check_value_rgb(t_info *map_parser);
void	join_map_line(t_parc *parc, t_info *info);
void	ft_creat_screen_bmp(t_info *info);
void	quicksort(double *dist, int *order, int left, int right);

#endif
