# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amansour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 10:19:33 by amansour          #+#    #+#              #
#    Updated: 2017/12/04 09:46:35 by amansour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

LDFLAGS_LIB = -L libft
LDLIBS = -lft
FLAGS = -Werror -Wall -Wextra

SRC_PATH = ./srcs
OBJ_PATH = ./obj
INCLUD  = ./include
LIB = libft/libft.a

SRC = checking.c delete_rooms.c file.c error.c link.c\
	main.c map.c print_ants.c room.c path.c path2.c\

OBJ = $(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	@gcc $(OBJ) $(LDFLAGS_LIB) $(LDLIBS)  -o $(NAME)
	@echo "\033[1;7;34mLEM_IN\t\033[1;7;33mCompilation\t\033[0m👌"

$(LIB):
	@make -C libft

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(FLAGS) -I $(INCLUD) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME) $(LIB)

re: fclean all
