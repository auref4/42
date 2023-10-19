#include "pipex.h"
#include "minishell.h"

int	search_builtins(t_cmd *cmd, t_struct_env *s)
{
	if (cmd->argv[0] && !ft_strcmp(cmd->argv[0], "echo"))
		builtins_echo(cmd->argv);
	else if (cmd->argv[0] && !ft_strcmp(cmd->argv[0], "pwd"))
	{
		if (!builtins_pwd(cmd->argv))
			return (0);
	}
	else if (cmd->argv[0] && !ft_strcmp(cmd->argv[0], "env"))
	{
		if (!builtins_env(cmd->argv, s->lst_env))
			return (0);
	}
	return (1);
}
