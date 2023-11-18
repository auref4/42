# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auferran <auferran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/16 17:16:20 by auferran          #+#    #+#              #
#    Updated: 2023/11/18 21:00:29 by auferran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

HEADER = minishell.h

SRCS =	main.c manage.c manage_sig.c utils.c\
		utils_2.c fill_lst.c fill_lst_file.c fill_lst_arg.c\
		lst_cmd_utils.c lst_arg_utils.c lst_file_utils.c lst_env_utils.c\
		quote.c quote_2.c prompt_utils.c token.c\
		init_lst_env.c init_lst_env_2.c init_lst_env_2.c manage_dollar.c\
		manage_dollar_utils.c manage_dollar_query.c itoa .c free_all.c\
		dup_str.c update_shlvl.c check_prompt.c error.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

CC = cc

FLAGS = -Wall -Werror -Wextra -g

$(NAME) : $(OBJS) $(HEADER)
		 $(CC) $(FLAGS) $(OBJS) -lreadline -o $(NAME)

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
