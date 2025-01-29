NAME = minishell

CFILES = main.c parsing.c ft_neo_split.c ft_neo_split2.c pipes.c init.c builtin.c builtin2.c builtin3.c shi_in.c sighand.c utils.c utils2.c launcher.c heredoc.c trade_dollar.c tokenization.c duct_tape.c
OFILES = $(CFILES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lreadline -lncurses   # Link readline and ncurses libraries
	
LIBFT = ./libft/libft.a
INCLUDES = -I . -I ./libft    # Add the libft directory for includes

.PHONY: all clean fclean re libft

# Build target
all: $(NAME)

# Link the executable
$(NAME): $(OFILES) $(LIBFT)
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT) $(LIBS) -o $(NAME)

# Build libft
$(LIBFT):
	@make -C ./libft

# Rule for generating object files
%.o: %.c minishell.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean object files
clean:
	@make -C ./libft clean
	rm -f $(OFILES)

# Clean all (object files + executable)
fclean: clean
	@make -C ./libft fclean
	rm -f $(NAME)

# Rebuild everything
re: fclean all
