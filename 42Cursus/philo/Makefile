NAME = philo

HEADER = philo.h

SRCS =	main.c\
		check_arg.c\
		error.c\
		ft_atoi.c\
		philo.c\
		init.c\
		create_thread.c\
		create_thread_utils.c\
		manage_time.c\
		lock_unlock.c\

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
