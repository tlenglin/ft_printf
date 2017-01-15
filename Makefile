# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 14:23:56 by tlenglin          #+#    #+#              #
#    Updated: 2017/01/15 15:38:11 by tlenglin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

SRC = main.c conversion_specifier.c width_and_precision.c flag.c ft_printf.c length_modifier.c  ft_itoa_base.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = gcc

LIBFT_PATH = ./libft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L./libft -lft

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
