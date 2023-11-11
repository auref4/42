#include "pipex.h"
#include "minishell.h"

int	search_builtins(t_cmd *cmd, t_struct_env *s)
{
	if (cmd->argv[0] && !ft_strcmp(cmd->argv[0], "echo"))
		g_exit = builtins_echo(cmd->argv);
	else if (cmd->argv[0] && !ft_strcmp(cmd->argv[0], "pwd"))
		g_exit = builtins_pwd(cmd->argv);
	else if (cmd->argv[0] && !ft_strcmp(cmd->argv[0], "export"))
		g_exit = builtins_export(cmd->argv, s);
	else if (cmd->argv[0] && !ft_strcmp(cmd->argv[0], "unset"))
		g_exit = builtins_unset(cmd->argv, s);
	else if (cmd->argv[0] && !ft_strcmp(cmd->argv[0], "env"))
		g_exit = builtins_env(cmd->argv, s->lst_env);
	else
		return (0);
	return (1);
}
