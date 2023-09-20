/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:10:25 by auferran          #+#    #+#             */
/*   Updated: 2023/09/16 20:04:48 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	manage_prompt(char *prompt, char **env)
{
	(void) env;
	t_lst_cmd	*cmd;

	cmd = NULL;
	if (!init_lst(prompt, &cmd))
		return (0);
	if (!check_prompt(prompt, cmd))
		return (ft_lst_clear(&cmd), 1);
	//GO PIPEX !
	ft_lst_clear(&cmd);
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
