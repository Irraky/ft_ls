# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drecours <drecours@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/27 14:12:36 by drecours          #+#    #+#              #
#    Updated: 2017/05/01 14:20:08 by drecours         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_putchar.c \
	  ft_putendl.c \
	  ft_putstr.c \
	  ft_strlen.c \
	  ft_wstrlen.c \
	  ft_tolower.c \
	  ft_itoa.c \
	  ft_ilen.c \
	  ft_isdigit.c \
	  ft_strcpy.c \
	  ft_putendl_fd.c \
	  ft_printf.c \
	  ft_itoa_base.c \
	  ft_wcsize.c \
	  ft_exit.c \
	  convpart1.c \
	  convpart2.c \
	  convpart3.c \
	  convpart4.c \
	  convpart5.c \
	  convpart6.c \
	  get_data.c \
	  convert.c \
	  flagspart1.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -c $(FLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
