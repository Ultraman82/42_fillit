NAME = fillit

CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I libft/

SRC = read.c \
	  split.c \
	  valid.c \
	  map.c \
	  solve.c \

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

.PHONY = all clean fclean clean re

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(OBJ) $(LIBFT) -o $(NAME)
	@echo "Compiling has done."

clean:
	@rm -rf $(OBJ)
	@make -C libft clean
	@echo "Object Files have deleted."

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@echo "Executable files have deleted."

re: fclean all
