#include "minitalk.h"
#include <stdio.h>

void ft_putstr(char *str)
{
  int   i;

  i = 0;
  while(str[i])
    i++;
  write(1, str, i);
}

void  ft_error(int nb)
{
  if (nb == 1)
    ft_putstr("le nombre d'arguments est incorrect.\n");
  if (nb == 2)
    ft_putstr("le pid ne peut pas etre un unsigned int.\n");
}

int	ft_atoi(const char *theString)
{
	int	i;
	int	signe;
	int	nb;

	signe = 0;
	i = 0;
	nb = 0;
	while ((theString[i] && (theString[i] >= '\t' && theString[i] <= '\r'))
		|| (theString[i] == ' '))
		i++;
	if ((theString[i] && theString[i] == '-') || theString[i] == '+')
	{
		if (theString[i] == '-')
			signe = 1;
		i++;
	}
	while (theString[i] && theString[i] >= '0' && theString[i] <= '9')
	{
		nb = nb * 10 + (theString[i] - 48);
		i++;
	}
	if (signe == 1)
		nb = nb * -1;
	return (nb);
}

void  voyager(char byte, int pid_server)
{
  int   i;

  i = 7;
  while (i >= 0)
  {
    if ((byte >> i) % 2 == 0)
    {
      printf("byte = 0\n");
      kill(pid_server, SIGUSR1);
    }
    if ((byte >> i) % 2 == 1)
    {
      printf("byte = 1\n");
      kill(pid_server, SIGUSR2);
    }
    printf("avant pause\n");
    i--;
    pause();
  }
}

void  send_message(int pid_server, char *str)
{
  int   i;

  i = 0;
  if (pid_server >= 0)
  {
    while(str[i])
    {
      voyager(str[i], pid_server);
      i++;
    }
    voyager(str[i], pid_server);
  }
  else
    ft_error(2);
}

void  sig_handler(int nb)
{
  (void) nb;
}

int main(int argc, char **argv)
{
  signal(SIGUSR1, sig_handler);
  if (argc == 3)
   send_message(ft_atoi(argv[1]), argv[2]);
  else
    ft_error(1);
}
