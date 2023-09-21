/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:15:56 by auferran          #+#    #+#             */
/*   Updated: 2023/09/16 17:15:57 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_prompt(char *prompt, t_lst_cmd *cmd)
{
	(void) cmd;
	int		i;
	int		in_s_quote;
	int		in_d_quote;
	int		ret;
	char	*quote1;
	char	*quote2;
	char	*quote3;

	i = 0;
	quote1 = "simple";
	quote2 = "double";
	quote3 = "simple et double";
	while (prompt[i])
	{
		in_s_quote = 0;
		in_d_quote = 0;
		ret = in_quote(prompt, i, &in_s_quote, &in_d_quote);
		if (ret == 1)
		{
			if (in_s_quote == 1 && in_d_quote == 0)
				printf("la lettre (%c) est entre %s quotes\n", prompt[i], quote1);
			else if (in_s_quote == 0 && in_d_quote == 1)
				printf("la lettre (%c) est entre %s quotes\n", prompt[i], quote2);
			else if (in_s_quote == 1 && in_d_quote == 1)
				printf("la lettre (%c) est entre %s quotes\n", prompt[i], quote3);
			else
				printf("probleme dans fonction\n");
		}
		else
			printf("la lettre (%c) n'est pas entre des quotes\n", prompt[i]);
		i++;
	}
	return (1);
}
