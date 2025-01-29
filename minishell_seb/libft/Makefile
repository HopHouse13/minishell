CFILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
		ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
		ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
		ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c ft_striteri.c \
		get_next_line.c ft_printfd.c putsomething.c putsomething2.c

OFILES = ${CFILES:.c=.o}

BONUS =	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
		ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

ALLCFILES = ${CFILES} ${BONUS}

ALLOFILES = ${ALLCFILES:.c=.o}

CC = gcc -Wall -Wextra -Werror -I ./

NAME = libft.a

all: $(NAME)

$(NAME): 
		$(CC) -c $(CFILES) -I ./
		ar rsc $(NAME) $(OFILES)

bonus:
		$(CC) -c $(ALLCFILES) -I ./
		ar rsc $(NAME) $(ALLOFILES)

clean:
		rm -f $(ALLOFILES)

fclean: clean
		rm -f $(NAME)

re: fclean all
