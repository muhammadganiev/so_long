# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 16:43:30 by muganiev          #+#    #+#              #
#    Updated: 2022/10/16 15:37:44 by muganiev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Werror -Wextra

FLAGS = -crs

mlx = ./mlx/libmlx.a

FILES = ./src/mandatory/parsing/read_split.c ./src/mandatory/parsing/check_map1.c ./src/mandatory/parsing/check_map2.c\
		./src/mandatory/drawnfree/draw.c ./src/mandatory/drawnfree/free.c\
		./src/mandatory/init/initData.c ./src/mandatory/move/move.c\
		so_long.c

OBJECTS = $(FILES:.c=.o)

OBJECTS = $(FILES_BONUS:.c=.o)

LIBFT = cd libft && make

LIB = libft/libft.a

$(NAME)	:
		$(LIBFT)
		make -C ./mlx
		gcc $(CFLAGS) -o so_long $(FILES) $(LIB) $(mlx) -framework OpenGL -framework AppKit

all : $(NAME)

clean :
		rm -f $(OBJS)
		make clean -C mlx

fclean : clean
		rm -f $(NAME)
		make clean -C mlx

re : fclean all