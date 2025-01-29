# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbret <pbret@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 16:53:10 by pbret             #+#    #+#              #
#    Updated: 2025/01/16 12:34:31 by pbret            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft
LIBRARY		= $(NAME).a
SRCS_DIR	= srcs
OBJ_DIR 	= obj_$(NAME)

SRCS		= srcs/ft_bzero.c srcs/ft_isalnum.c srcs/ft_isalpha.c \
			srcs/ft_isdigit.c srcs/ft_isprint.c srcs/ft_isascii.c \
			srcs/ft_memcpy.c srcs/ft_memset.c srcs/ft_strlen.c \
			srcs/ft_memmove.c srcs/ft_memchr.c srcs/ft_memcmp.c \
			srcs/ft_strlcpy.c srcs/ft_strlcat.c srcs/ft_strchr.c \
			srcs/ft_strrchr.c srcs/ft_strncmp.c srcs/ft_strnstr.c \
			srcs/ft_toupper.c srcs/ft_tolower.c srcs/ft_atoi.c \
			srcs/ft_calloc.c srcs/ft_strdup.c srcs/ft_substr.c \
			srcs/ft_strjoin.c srcs/ft_strtrim.c srcs/ft_itoa.c \
			srcs/ft_strmapi.c srcs/ft_striteri.c srcs/ft_putchar_fd.c \
			srcs/ft_putstr_fd.c srcs/ft_split.c srcs/ft_putendl_fd.c \
			srcs/ft_putnbr_fd.c srcs/ft_lstnew_bonus.c \
			srcs/ft_lstadd_front_bonus.c srcs/ft_lstsize_bonus.c \
			srcs/ft_lstlast_bonus.c srcs/ft_lstadd_back_bonus.c\
			srcs/ft_lstdelone_bonus.c srcs/ft_lstclear_bonus.c \
			srcs/ft_lstiter_bonus.c srcs/ft_lstmap_bonus.c
						
OBJS		= $(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)
CC			= cc
RM			= rm -rf
AR			= ar rcs
CFLAGS		= -Wall -Wextra -Werror -ggdb -I$(SRCS_DIR)

all:		$(LIBRARY)

$(LIBRARY):	$(OBJS) 
			$(AR) $(LIBRARY) $(OBJS)
			@echo "\033[32m""Compilation de $(LIBRARY) est terminée!""\033[0m"

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) -c $< -o $@
	
clean:
			$(RM) $(OBJ_DIR)
			@echo "\033[36m""Répertoire $(OBJ_DIR) supprimé.""\033[0m"

fclean:		clean
			$(RM) $(LIBRARY)
			@echo "\033[36m""Fichier $(LIBRARY) supprimé.""\033[0m"

re:			fclean 	all

.PHONY: all clean fclean re
