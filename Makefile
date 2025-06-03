CC = cc

CFLAGS = -g  -Wall -Wextra -Werror

MINI_SRC = tokenization_utils.c handlers.c minishell.c misc_utils.c base_utils.c tree_utils.c

MINI_OBJ = $(MINI_SRC:.c=.o)

NAME = minishell

LIBFT = libft.a

LIBFT_SRC = $(wildcard $(LIBFT_DIR)/*.c)

LIBFT_OBJ = $(wildcard $(LIBFT_DIR)/*.o)

LIBFT_DIR = libft

all: $(NAME)
	./$(NAME)

$(NAME): $(MINI_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(MINI_OBJ)  -o $@  $(LIBFT) -lreadline -ltermcap

$(LIBFT): $(LIBFT_SRC)
	make -C libft all
	mv libft/libft.a .

%.o: %.c minishell.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(MINI_OBJ)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all
