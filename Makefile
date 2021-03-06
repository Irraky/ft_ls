# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drecours <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/21 13:45:10 by drecours          #+#    #+#              #
#    Updated: 2017/09/25 11:53:13 by drecours         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
FLAGS = -Werror -Wall -Wextra
SRC = details.c \
	  ft_memalloc.c \
	  ft_memset.c \
	  ft_strchr.c \
	  ft_strcmp.c \
	  get_data.c \
	  clean_it.c \
	  my_ls.c \
	  rights.c \
	  parsing_args.c \
	  new_elem.c \
	  display_file.c \
	  new_node.c \
	  ft_strdup.c \
	  manage_dir.c \
	  ft_joinfree.c \
	  ft_strlen.c \
	  ft_strrchr.c \
	  ft_strsub.c \
	  ft_strdel.c \
	  ft_memdel.c \
	  count_blocks.c \
	  sort_list.c \
	  insert_node.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_putnbr_fd.c \
	  ft_putchar_fd.c

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
