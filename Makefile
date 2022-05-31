# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoukhart <aoukhart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 22:24:55 by aoukhart          #+#    #+#              #
#    Updated: 2022/05/30 21:25:26 by aoukhart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c\
		utils.c\
		utils_2.c\
		Moves.c\
		Map_Drawing.c\
		utils_map.c\
		check_map.c\

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

FRAMEWORK = -framework OpenGL -framework AppKit -lmlx

all : $(NAME)

$(NAME) : $(OBJ)
	@gcc $(FLAGS) $(FRAMEWORK) $(SRC) -o $(NAME)

clean : 
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all