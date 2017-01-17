# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/16 11:02:50 by tlenglin          #+#    #+#              #
#    Updated: 2017/01/16 22:56:01 by tlenglin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_bzero.c ft_atoi.c conversion_specifier.c width_and_precision.c flag.c ft_printf.c length_modifier.c  ft_itoa_base.c ft_itoa.c ft_memalloc.c ft_putchar.c ft_putstr.c ft_strdup.c ft_strnew.c ft_memset.c ft_strlen.c ft_strsub.c ft_strcpy.c ft_isprint.c

FLAGS = -Wall -Wextra -Werror

LIBFT_PATH = ./libft

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRC) ft_printf.h
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)
	rm -f ft_printf.h.gch

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
