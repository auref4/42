/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:10:25 by auferran          #+#    #+#             */
/*   Updated: 2023/09/25 17:01:52 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_lst(t_lst_cmd **cmd)
{
	t_lst_cmd	*lst_new;

	lst_new = NULL;
	lst_new = ft_lst_new_cmd();
	if (!lst_new)
		return (0);
	ft_memset(lst_new, 0, sizeof(t_lst_cmd));
	ft_lst_add_back_cmd(lst_new, cmd);
	return (1);
}

void	test_pipex(t_lst_cmd *cmd, char **env)
{
	int	i;
	int	y;
	int	x;

	(void) env;
	i = 1;
	y = 1;
	x = 1;
	while (cmd != NULL)
	{
		printf("_______________________\n");
		printf("Maillon numero %d cmd\n\n", i);
		while (cmd->arg != NULL)
		{
			printf("Maillon numero %d arg\n\n", y);
			printf("name = %s\n", cmd->arg->name);
			printf("arg = %s\n", cmd->arg->arg);
			cmd->arg = cmd->arg->next;
			y++;
		}
		while (cmd->file != NULL)
		{
			printf("Maillon numero %d file\n\n", x);
			printf("infile = %s\n", cmd->file->infile);
			printf("outfile = %s\n", cmd->file->outfile);
			printf("outfile_type = %d\n", cmd->file->outfile_type);
			printf("limiter = %s\n", cmd->file->limiter);
			cmd->file = cmd->file->next;
			x++;
		}
		cmd = cmd->next;
		i++;
		y = 1;
		x = 1;
	}
}

int	manage_prompt(char *prompt, char **env)
{
	t_lst_cmd	*cmd;

	(void) env;
	cmd = NULL;
	if (!check_prompt(prompt, cmd))
		return (1);
	if (!init_lst(&cmd))
		return (0);
	if (!fill_lst(prompt, &cmd))
		return (1);
	test_pipex(cmd, env);
	//PAS OUBLIER DE FREE
	return (1);
}

void	minishell(char **env)
{
	char		*prompt;

	(void) env;
	manage_sig();
	while (1)
	{
		prompt = readline("(auferran&malancar)-[~/minishell]$ ");
		if (!prompt || !ft_strcmp("exit", prompt))
		{
			if (!ft_strcmp("exit", prompt))
				free(prompt);
			printf("exit\n");
			return ;
		}
		else if (prompt && !manage_prompt(prompt, env))
		{
			free(prompt);
			return ;
		}
		free(prompt);
	}
}
