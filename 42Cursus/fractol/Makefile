# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auferran <auferran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 21:25:58 by auferran          #+#    #+#              #
#    Updated: 2023/03/23 03:18:57 by auferran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

HEADER = fractol.h

SRCS =	main.c\
		fractol.c\
		create_fractal.c\
		create_fractal2.c\
		colors.c\
		zoom_and_dezoom.c\
		move.c\
		error.c\
		check_arg.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

CC = cc

FLAGS = -Wall -Werror -Wextra -g

$(NAME) : $(OBJS) $(HEADER)
		 $(CC) $(FLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
		$(CC) $(FLAGS) -MMD -I/usr/include -Imlx_linux -O3 -c $< -o $@

all : $(NAME)

clean :
		rm -f $(OBJS) $(DEPS)

fclean : clean
		rm -f $(NAME) $(DEPS)

re : fclean all

-include : $(DEPS)

.PHONY: all clean fclean re
