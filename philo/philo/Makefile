NAME = philo

SRC = start.c parser.c simulation.c utils.c init_all.c

OBJ = $(SRC:.c=.o)

CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

$(NAME): $(OBJ)
	@echo "\nCompiling --->"
	@$(CC) -o $@  $^
	@echo "Done\n"

clean:
	@rm -rf $(OBJ)
	@echo "\nDelete objects\n"

fclean: clean
	@rm -rf $(NAME)
	@echo "\nDelete all\n"

re: fclean all
