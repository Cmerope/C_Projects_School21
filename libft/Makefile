# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmerope <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 14:11:22 by cmerope           #+#    #+#              #
#    Updated: 2020/11/25 17:31:21 by cmerope          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	libft.a

SRCS		= 	ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memmove.c ft_memcmp.c ft_strchr.c ft_strlcpy.c ft_atoi.c ft_strrchr.c ft_strncmp.c ft_strdup.c ft_calloc.c ft_strnstr.c ft_strlcat.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_substr.c ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c

SRCS_BONUS	=	ft_lstnew.c	ft_lstadd_front.c	ft_lstsize.c		ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c	ft_lstclear.c	ft_lstiter.c	ft_lstmap.c

OBJS		= 	${SRCS:.c=.o}

OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

CFLAGS		= 	-Wall -Werror -Wextra

HEADER		=	./libft.h

FHEADER		=	-I

CC			=	gcc

.c.o:
			${CC} ${CFLAGS} ${FHEADER} ${HEADER} -c $< -o $(<:.c=.o)

all:		${NAME}

$(NAME): 	${OBJS} ${HEADER}
			ar rcs ${NAME} ${OBJS}
						
clean:
			rm -f ${OBJS} ${OBJS_BONUS}

fclean: 	clean
			rm -f ${NAME}
			
re: 		fclean all

bonus:		${OBJS} ${OBJS_BONUS}
			ar rcs ${NAME} ${OBJS} ${OBJS_BONUS}

.PHONY:		all clean fclean re
