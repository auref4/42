#include "minitalk.h"
#include <stdio.h>

void  ft_putchar(char c)
{
  write(1, &c, 1);
}

void  ft_write_lst(t_lst  *lst)
{
  while(lst)
  {
   ft_putchar(lst->character);
   lst = lst->next;
  }
}

t_lst   *ft_lstlast(t_lst *lst)
{
  int   i;
  
  i = 0;
  while (lst)
  {
    lst = lst->next;
    i++;
  }
  return (lst);
}

t_lst   *ft_elmt_new(char c)
{
  t_lst   *new;
  
  new = malloc(sizeof(t_lst));
  if (!new)
    return (NULL);
  new->character = c;
  new->next = NULL;
  return (new);
}

void  ft_lstadd_back(t_lst *lst, t_lst *new)
{
  t_lst  *tmp;
  if(lst == NULL)
  {
    lst = new;
    return ;
  }
  tmp = ft_lstlast(lst);
  tmp->next = new;
}

void  ft_putnbr(int nb)
{
  if (nb > 9)
    ft_putnbr(nb / 10);
  ft_putchar((nb % 10) + 48);  
}

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)pointer;
	while (i < count)
	{
		p[i] = (unsigned char)value;
		i++;
	}
	return (pointer);
}

void  def_gest(t_sigaction sigact)
{
  sigaction(SIGUSR1, &sigact, NULL);
  sigaction(SIGUSR2, &sigact, NULL);
}

void  sig_receipt2(int sig, int pid_client, int *i, char *c)
{
  static int   count;
  static char  bi;

  if (sig == SIGUSR1)
  {
    bi = bi * 2;
    count++;
    printf("test1\n");
    kill (SIGUSR1, pid_client);
  }
  if (sig == SIGUSR2)
  {
    bi = bi * 2 + 1;
    count++;
    printf("test2");
    kill (SIGUSR2, pid_client);
  }
  if (sig == -4)
  {
    *c = bi;
    *i = count;
    if (count == 8)
    {
      count = 0;
      bi = 0;
    }
  }
}

void  sig_receipt(int sig, siginfo_t *info, void *v)
{
  (void)  v;

  if (sig == SIGUSR1 || sig == SIGUSR2)
    sig_receipt2(sig, info->si_pid, NULL, NULL);
}

void  def_sigact(t_sigaction *sigact)
{
  ft_memset(sigact, 0, sizeof(t_sigaction));
  sigact->sa_sigaction = &sig_receipt;
}

void  get_char(int *i, char *c, t_lst *lst)
{
  t_lst   *new;

  if (*i < 8)
    sig_receipt2(-4, 0, i, c);
  else if (*i == 8)
  {
    new = ft_elmt_new(*c);
    ft_lstadd_back(lst, new);
    if (*c == '\0')
      ft_write_lst(lst);
    *i = 0;
    *c = 0;
  }
}

int   main(void)
{
  //t_sigaction   sigact;
  t_lst  *lst;
  int   i;
  char  c;

  i = 0;
  c = 0;
  lst = NULL;
  ft_putnbr(getpid());
  //def_sigact(&sigact);
  //def_gest(sigact);
  while(4)
  {
    //get_char(&i, &c, lst);
    //pause();
  }
}
