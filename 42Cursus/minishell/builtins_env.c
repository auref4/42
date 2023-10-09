#include "minishell.h"

void	builtins_env(t_lst_arg *arg ,t_lst_env *lst_env)
{
	if (arg->next)
	{
		printf ("no options or arguments are required\n");
		return ;
	}
	while (lst_env)
	{
		if (lst_env->line)
			printf("%s\n", lst_env->line);
		lst_env = lst_env->next;
	}
}
