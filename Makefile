# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drecours <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/21 13:45:10 by drecours          #+#    #+#              #
#    Updated: 2017/06/21 18:49:01 by drecours         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
FLAGS = -g -Wall -Werror -Wextra
PRINTF_DIR=ft_printf
SRC = details.c \
	  ft_memalloc.c \
	  ft_memset.c \
	  ft_strchr.c \
	  ft_strcmp.c \
	  get_data.c \
	  my_ls.c \
	  manage_args.c \
	  new_elem.c 

OBJ = $(SRC:.c=.o)
CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	make -C ft_printf/
	$(CC) $(FLAGS) -o $(NAME) $(SRC) ft_printf/libftprintf.a

clean:
	rm -f $(OBJ)
	make -C ft_printf $@
	
fclean: clean
	rm -rf $(NAME)
	rm -rf ft_printf/libftprintf.a

re: fclean all

.PHONY: clean fclean re all