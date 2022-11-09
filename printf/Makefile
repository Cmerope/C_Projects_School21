# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmerope <cmerope@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/31 03:10:37 by cmerope           #+#    #+#              #
#    Updated: 2021/01/31 03:27:52 by cmerope          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =  ft_printf.c\
		ft_printf_utils_count.c\
		ft_printf_utils_write.c\
		ft_printf_write_sc.c\
		ft_printf_write_diu.c\
		ft_printf_write_hex.c\
		ft_printf_types.c

OBJ =   ft_printf.o\
		ft_printf_utils_count.o\
		ft_printf_utils_write.o\
		ft_printf_write_sc.o\
		ft_printf_write_diu.o\
		ft_printf_write_hex.o\
		ft_printf_types.o

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) ft_printf.h
	ar rc $(NAME) $(OBJ)

bonus:	$(OBJ) $(OBJ_BONUS) ft_printf.h
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
