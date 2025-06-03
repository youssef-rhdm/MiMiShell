CC = cc

<<<<<<< HEAD
CFLAGS = -g  -Wall -Wextra -Werror

MINI_SRC = tokenization_utils.c handlers.c minishell.c misc_utils.c base_utils.c tree_utils.c

MINI_OBJ = $(MINI_SRC:.c=.o)
=======
CFLAGS = # -Wall -Wextra -Werror

MIMI_SRC = main.c

MIMI_OBJ = $(MIMI_SRC:.c=.o)
>>>>>>> a63dcefe0f7146106df1df0bc7e118cc4214ecf4

NAME = minishell

LIBFT = libft.a

LIBFT_SRC = $(wildcard $(LIBFT_DIR)/*.c)

LIBFT_OBJ = $(wildcard $(LIBFT_DIR)/*.o)

<<<<<<< HEAD
LIBFT_DIR = libft
=======
LIBFT_DIR = coreutils
>>>>>>> a63dcefe0f7146106df1df0bc7e118cc4214ecf4

all: $(NAME)
	./$(NAME)

$(NAME): $(MINI_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(MINI_OBJ)  -o $@  $(LIBFT) -lreadline -ltermcap

<<<<<<< HEAD
$(LIBFT): $(LIBFT_SRC)
	make -C libft all
	mv libft/libft.a .

=======
$(NAME): $(MIMI_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(MIMI_OBJ)  -o $@ -lreadline $(LIBFT)

$(LIBFT): $(LIBFT_SRC)
	make -C coreutils all
	mv coreutils/libft.a .

>>>>>>> a63dcefe0f7146106df1df0bc7e118cc4214ecf4
%.o: %.c minishell.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
<<<<<<< HEAD
	$(RM) $(MINI_OBJ)
	make -C libft clean
=======
	$(RM) $(MIMI_OBJ)
	make -C coreutils clean
>>>>>>> a63dcefe0f7146106df1df0bc7e118cc4214ecf4

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: clean all
