# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auferran <auferran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 23:32:07 by auferran          #+#    #+#              #
#    Updated: 2023/03/18 07:00:45 by auferran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADER = push_swap.h

SRCS =	check_arg.c\
		check_doublon.c\
		ft_atoi.c\
		ft_error.c\
		ft_split.c\
		init_lst.c\
		lst_utils1.c\
		lst_utils2.c\
		main.c\
		my_algo_utils.c\
		operation1.c\
		operation2.c\
		operation3.c\
		push_swap.c\
		sort_utils.c\
		sort.c

OBJS = $(SRCS:.c=.o)

CC = cc

FLAGS = -Wall -Werror -Wextra

$(NAME) : $(OBJS) $(HEADER)
		 $(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(SRCS)
		$(CC) $(FLAGS) -c -o $@ $<

all : $(NAME)

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
