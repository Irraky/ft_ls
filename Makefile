# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drecours <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/21 13:45:10 by drecours          #+#    #+#              #
#    Updated: 2017/06/21 16:07:25 by drecours         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls.a
FLAGS = -Wall -Werror -Wextra
PRINTF_DIR=ft_printf
SRC = details.c \
	  ft_memalloc.c \
	  ft_memset.c \
	  ft_strchr.c \
	  get_data.c \
	  my_ls.c \
	  manage_args.c \
	  new_elem.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	(cd $(PRINTF_DIR) && $(MAKE))

clean:
	rm -f $(OBJ)
	(cd $(PRINTF_DIR) && $(MAKE) $@)

fclean: clean
	rm -rf $(NAME)
	(cd $(PRINTF_DIR) && $(MAKE) $@)

re: fclean all

.PHONY: clean fclean re all
