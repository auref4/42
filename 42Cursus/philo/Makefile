# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auferran <auferran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 16:21:04 by auferran          #+#    #+#              #
#    Updated: 2023/07/09 16:21:05 by auferran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEADER = philo.h

SRCS =	main.c\
		check_arg.c\
		error.c\
		ft_atoi.c\
		ft_strcmp.c\
		prep_philo.c\
		init.c\
		philosophers.c\
		philosophers_2.c\
		manage_time.c\
		lock_unlock.c\
		death.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

CC = cc

FLAGS = -Wall -Werror -Wextra -g

$(NAME) : $(OBJS) $(HEADER)
		 $(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
		$(CC) $(FLAGS) -MMD -c $< -o $@

all : $(NAME)

clean :
		rm -f $(OBJS) $(DEPS)

fclean : clean
		rm -f $(NAME) $(DEPS)

re : fclean all

-include : $(DEPS)

.PHONY: all clean fclean re
