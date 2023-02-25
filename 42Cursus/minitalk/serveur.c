#include "minitalk.h"
#include <stdio.h>

void  ft_putstr(char *str)
{
  int   i;

  i = 0;
  while(str[i])
    i++;
  write(1, str, i);
}

void  ft_putchar(char c)
{
  write(1, &c, 1);
}

int   ft_lst_size(t_lst *lst)
{
  int   i;

  i = 0;
  while (lst)
  {
    i++;
    lst = lst->next;
  }
  return (i);
}

char  *ft_lst_join(t_lst *lst)
{
  int   i;
  char  *str;

  i = 0;
  str = malloc(sizeof(char) * ft_lst_size(lst));
  if (!str)
    return (NULL);
  while (lst)
  {
    str[i] = lst->character;
    i++;
    lst = lst->next;
  }
  return (str);
}

t_lst   *ft_lstlast(t_lst *lst)
{
  int   i;
  
  i = 0;
  while (lst->next)
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

void  ft_lstadd_back(t_lst **lst, t_lst *new)
{
  t_lst  *tmp;

  if(*lst == NULL)
  {
    *lst = new;
    return ;
  }
  tmp = ft_lstlast(*lst);
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
  sigaction(SIGINT, &sigact, NULL);
}

void  sig_receipt(int sig, siginfo_t *info, void *v)
{
  (void)  v;
  static t_lst   *lst;
  static int   count;
  static char  bi;
  char  *str;
  
  if (sig == SIGUSR1 || sig == SIGUSR2)
  {
    if (sig == SIGUSR1)
      bi = bi * 2;
    if (sig == SIGUSR2)
      bi = bi * 2 + 1;
    count++;
    if(count == 8)
    {
      ft_lstadd_back(&lst, ft_elmt_new(bi));
      if (bi == '\0')
      {
        str = ft_lst_join(lst);
        ft_putstr(str);
        ft_putchar('\n');
      }
      count = 0;
      bi = 0;
    }
    kill(info->si_pid, SIGUSR1);
  }
}

void  def_sigact(t_sigaction *sigact)
{
  ft_memset(sigact, 0, sizeof(t_sigaction));
  sigact->sa_sigaction = &sig_receipt;
  sigact->sa_flags = SA_SIGINFO;
}

int   main(void)
{
  t_sigaction   sigact;

  ft_putnbr(getpid());
  ft_putchar('\n');
  def_sigact(&sigact);
  def_gest(sigact);
  while(4);
}
