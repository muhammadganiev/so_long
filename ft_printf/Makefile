# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 16:20:28 by muganiev          #+#    #+#              #
#    Updated: 2022/10/17 16:21:06 by muganiev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJS = ${SRCS:.c=.o}

RM = rm -f

CCF = gcc -Wall -Wextra -Werror

LIB = ar -rcs

SRCS = ft_printf.c conv1.c conv2.c

all: ${NAME}

$(NAME): ${OBJS}
		@${LIB} ${NAME} ${OBJS}

%.o : %.c ft_printf.h
	@${CCF} -c $< -o $@

clean:
		@${RM} ${OBJS}

fclean:	clean
		@${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re