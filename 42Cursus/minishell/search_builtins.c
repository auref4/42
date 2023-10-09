#include "minishell.h"

void	search_builtins(t_lst_cmd *cmd, t_lst_env **lst_env)
{
	cmd = ft_lst_last_cmd(cmd);
	if (cmd->arg)
	{
		if (cmd->arg->name)
		{
			if (!ft_strcmp(cmd->arg->name, "env"))
				builtins_env(cmd->arg, *lst_env);
			else if (!ft_strcmp(cmd->arg->name, "export"))
				builtins_export(cmd->arg, lst_env);
		}
	}
}
