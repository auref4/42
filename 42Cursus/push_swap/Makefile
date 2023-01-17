# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auferran <auferran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 23:32:07 by auferran          #+#    #+#              #
#    Updated: 2023/01/17 23:33:23 by auferran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

HEADER = push_swap.h

SRCS =

OBJS = $(SRCS:.c=.o)

CC = cc

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
