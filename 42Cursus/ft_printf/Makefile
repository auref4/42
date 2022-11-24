# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auferran <auferran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 16:24:02 by auferran          #+#    #+#              #
#    Updated: 2022/11/24 18:27:07 by auferran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = libftprintf.h

SRCS =		ft_printf.c ft_check_pc_letter.c ft_print_char.c ft_print_type.c \
			ft_print_str.c ft_print_nbr.c ft_print_uns_nbr.c ft_print_hex.c
OBJS = $(SRCS:.c=.o)

CC = clang

FLAGS = -Wall -Werror -Wextra

$(NAME) : $(OBJS) $(HEADER)
		ar rcs $(NAME) $(OBJS)

BONUS =

OBJS_BONUS = $(BONUS:.c=.o)

%.o: %.c $(SRCS)
		$(CC) $(FLAGS) -c -o $@ $<

all : $(NAME)

bonus : $(OBJS_BONUS) $(OBJS)
		ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

clean :
		rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
