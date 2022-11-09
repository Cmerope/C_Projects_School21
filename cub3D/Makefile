# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmerope <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 18:06:17 by cmerope           #+#    #+#              #
#    Updated: 2021/04/29 18:07:21 by cmerope          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	cub3D

SRC_FILES	= 	start.c cub3d.c \
				parc/ft_parc.c parc/ft_parc_params1.c parc/ft_parc_params2.c \
				parc/ft_parc_utils1.c parc/ft_parc_utils2.c parc/ft_parc_utils3.c parc/ft_parc_utils4.c \
				math/math.c math/math_units1.c  math/math_units2.c math/math_units3.c \
				sprite/download.c sprite/sorty.c sprite/sprites.c \
				libft/ft_strchr.c libft/ft_split.c libft/ft_strjoin.c libft/ft_strlen.c \
				libft/ft_strncmp.c libft/get_next_line.c libft/ft_atoi_chr.c \
				units/screen_bmp.c units/where_player.c units/init_main.c units/init_buf.c units/steps.c units/exit.c \

# путь к папке
SRCS 		= 	$(addprefix srcs/,$(SRC_FILES))

OBJS 		= 	$(SRCS:.c=.o)

CC 			= 	gcc -g -Wall -Wextra -Werror

HEADERS		=	-Imlx -Iincludes

MLX			= 	libmlx.a
MLX_STAT 	= 	$(MLX) -framework OpenGL -framework Appkit

.c.o:
				@$(CC) $(HEADERS) -c $< -o $(<:.c=.o)
				@echo "---------Object files done------------"

all:			$(MLX) $(NAME)

$(MLX):
				@make -C mlx
				@cp mlx/$(MLX) .
				@echo "-----------Make MLX done--------------"

$(NAME): 		$(OBJS)
				@$(CC) -o $(NAME) $(OBJS) $(MLX_STAT)
				@echo "----------Make cub3D done-------------"

clean:
				@make clean -C mlx
				@rm -f $(OBJS)
				@echo "--------Removed object files----------"

mostlyclean: 	clean
				@rm -f $(NAME)
				@echo "-------Removed files without lib------"

fclean: 		clean
				@rm -f $(NAME)
				@rm -f $(MLX)
				@echo "---------Removed all files------------"

re: 			mostlyclean all
				@echo  "---------Remake cub3D done------------"

.PHONY:		all clean mostlyclean fclean re
