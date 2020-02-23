# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sreyne <sreyne@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 18:37:53 by lhaired           #+#    #+#              #
#    Updated: 2020/02/23 20:32:20 by sreyne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
FLAGS= -Wall -Werror -Wextra
NAME = libft.a

# SRC_DIR=src
SRC = ft_atoi.c ft_bzero.c ft_dup.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
ft_isdigit.c ft_ispace.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c\
ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c\
ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c\
ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c\
ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c\
ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c\
ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c\
ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c\
ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c\
ft_strtrim.c ft_tolower.c ft_toupper.c ft_wdcounter.c get_next_line.c\

# SRCD=$(addprefix $(SRC_DIR)/,$(SRCS))

INCLUDES=./inc/libft.h
OBJ_DIR=obj
OBJ=$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@ranlib $@

$(OBJ_DIR)/%.o: %.c $(INCLUDES)
	@mkdir -p obj
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all




# all: $(NAME)

# $(NAME): $(OBJD)
# 		gcc $(FLAGS) $(OPTION)
# 		ar rc $(NAME) $(OBJD)
# 		ranlib $(NAME)

# clean:
# 		rm -f $(OBJD)

# fclean: clean
# 		rm -f $(NAME)

# re: fclean all
