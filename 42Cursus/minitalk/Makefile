# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auferran <auferran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 00:25:40 by auferran          #+#    #+#              #
#    Updated: 2023/03/01 03:07:33 by auferran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSSRV			= server.c\
			 	utils.c\
				utils2.c\
			  	lst.c\
			  	lst2.c
SRCSCLT			= client.c\
				  utils.c
OBJSSRV			= ${SRCSSRV:.c=.o}
OBJCLT			= ${SRCSCLT:.c=.o}
HEADER			= minitalk.h
CC				= cc
FLAGS			= -Wall -Wextra -Werror
NAMESERVER		= server
NAMECLIENT		= client
NAMECLTBONUS	= client_bonus
NAMESRVBONUS	= server_bonus

all: $(NAMESERVER) $(NAMECLIENT)

bonus: $(NAMESRVBONUS) $(NAMECLTBONUS)

$(NAMESERVER): $(OBJSSRV) $(HEADER)
				 $(CC) $(FLAGS) $(OBJSSRV) -o $(NAMESERVER)

$(NAMESRVBONUS): $(OBJSSRV) $(HEADER)
				 $(CC) $(FLAGS) $(OBJSSRV) -o $(NAMESRVBONUS)

$(NAMECLIENT): $(OBJCLT) $(HEADER)
				 $(CC) $(FLAGS) $(OBJCLT) -o $(NAMECLIENT)

$(NAMECLTBONUS): $(OBJCLT) $(HEADER)
				 $(CC) $(FLAGS) $(OBJCLT) -o $(NAMECLTBONUS)
%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

clean:
		rm -f $(OBJSSRV) $(OBJCLT)

fclean: clean
		rm -f $(NAMESERVER) $(NAMECLIENT) $(NAMESRVBONUS) $(NAMECLTBONUS)

re:		fclean
		make all

.PHONY: all clean fclean re
