#include "push_swap.h"

int	get_first(t_lst *lst)
{
	int	nb_tmp;
	t_lst	*tmp;

	tmp = ft_lstmap(lst);
	shaker(&tmp);
	nb_tmp = tmp->nb;
	ft_lst_clear(&tmp);
	return (nb_tmp);
}

int	get_middle(t_lst *lst)
{
	int	i;
	int	nb_tmp;
	t_lst	*tmp;

	i = 0;
	tmp = ft_lstmap(lst);
	shaker(&tmp);
	while (i < ft_lst_size(tmp) / 2)
	{
		tmp = tmp->next;
		i++;
	}
	nb_tmp = tmp->nb;
	ft_lst_clear(&tmp);
	return (nb_tmp);
}

int	get_last(t_lst *lst)
{
	int	i;
	int	nb_tmp;
	t_lst	*tmp;

	i = 0;
	tmp = ft_lstmap(lst);
	shaker(&tmp);
	while (i < ft_lst_size(tmp) - 1)
	{
		tmp = tmp->next;
		i++;
	}
	nb_tmp = tmp->nb;
	ft_lst_clear(&tmp);
	return (nb_tmp);
}
