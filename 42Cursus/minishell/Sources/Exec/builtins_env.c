#include "pipex.h"

int	builtins_env(char **argv, t_lst_env *env_list)
{
	if (argv[1])
		return (1);
	while (env_list)
	{
		ft_putstr(env_list->line);
		ft_putstr("\n");
		env_list = env_list->next;
	}
	return (1);
}
