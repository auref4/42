#ifndef MINITALK_H
#define MINITALK_H

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

typedef struct sigaction t_sigaction;

typedef struct s_lst
{
  char  character;
  struct  s_lst  *next;
}   t_lst;

void  ft_putchar(char c);
void  ft_putnbr(int nb);
void  ft_putstr(char *str);
void  ft_error(int nb);
int   ft_atoi(const char *theString);
void  voyager(char byte, int pid_server);
void  send_message(int pid_server, char *str);
void  ft_write_lst(t_lst *lst);
t_lst  *ft_lstlast(t_lst *lst);
t_lst  *ft_elmt_new(char c);
void  ft_lstadd_back(t_lst *lst, t_lst *new);
void	*ft_memset(void *pointer, int value, size_t count);
void  def_gest(t_sigaction sigact);
void  sig_receipt2(int sig, int pid_client, int *i, char *c);
void  sig_receipt(int sig, siginfo_t *info, void *v);
void  def_sigact(t_sigaction *sigact);
void  get_char(int *i, char *c, t_lst *lst);
void  sig_handler(int nb);

#endif
