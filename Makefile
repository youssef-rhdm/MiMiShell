CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c

OBJ = $(SRC:.c=.o)

NAME = minishell

LIBFT = libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -lreadline $<  -o $@

$(LIBFT): coreutils/libft.h
	make -C coreutils all
	mv coreutils/libft.a .7747
*.o: *.c minishell.h coreutils/libft.h
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
