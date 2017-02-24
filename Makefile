# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/08 11:42:29 by rpatillo          #+#    #+#              #
#    Updated: 2016/04/25 15:33:36 by rpatillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fillit

FLAGS = -Wall -Wextra -Werror

CC = gcc
LIB = -L libft -lft
COMP = -I libft/ -I inc/

FILE_SRC = ./src/main.c \
		./src/parse.c \
		./src/solve.c \
		./src/modif.c \
		./src/other.c \
		./src/solver.c

FILE_OBJ = $(FILE_SRC:.c=.o)

all: $(NAME)

$(NAME): $(FILE_OBJ)
		make -C ./libft
		$(CC) -o $(NAME) $(FILE_OBJ) $(FLAGS) $(COMP) $(LIB) -g2
		@echo	""
		@echo	"Fillit by rpatillo & acabaill"
		@echo	""
		@echo "		Flags :"$(FLAGS)
		@echo	""

clean:
		make -C ./libft/ clean
		rm -Rfv $(FILE_OBJ)
		@clear

fclean: clean
		make -C libft/ fclean
		rm -Rfv $(NAME) $(FILE_OBJ)
		@clear

re: fclean all

.PHONY:	all clean fclean re
