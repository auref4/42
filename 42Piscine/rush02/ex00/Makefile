# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minh-ngu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 10:56:09 by minh-ngu          #+#    #+#              #
#    Updated: 2022/10/02 17:31:03 by minh-ngu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# make && make test && ./a.out

SOURCES     := $(shell find srcs -type f -name "*.c")  
OBJECTS     := $(patsubst srcs/%,srcs/%,$(SOURCES:.c=.o))

LIB = libft.a 
all: fclean $(LIB)

#test:
#	echo $(SOURCES)
#	echo $(OBJECTS)

#https://www.gnu.org/software/make/manual/make.html#Pattern-Rules
#a pattern rule ‘%.o : %.c’ says how to make any file stem.o from another file stem.c
#.c.o == %.o : %.c
#.c.o:
#	echo $< $@
#make ft_putstr.o => $< == ft_putstr.c , $@ == ft_putstr.o 
#$^ The names of all the prerequisites, with spaces between them

%.o: %.c
	gcc -Wall -Wextra -Werror -c -I./includes $< -o $@

$(LIB): $(OBJECTS)
	ar -rc $(LIB) srcs/*.o
	gcc -Wall -Wextra -Werror $(OBJECTS) -o rush-02

test:
	gcc -Wall -Wextra -Werror -g $(SOURCES) -o rush-02

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(LIB)

re: fclean all

.PHONY: all clean fclean re

