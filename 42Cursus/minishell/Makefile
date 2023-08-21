NAME = minishell

HEADER = minishell.h

SRCS =	main.c\
		minishell.c\
		manage_sig.c\
		utils.c\
		check_prompt.c

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
