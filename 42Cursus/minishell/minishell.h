#ifndef MINISHELL_H
#define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

void	minishell(char **env);
int		manage_sig();
int		ft_strcmp(const char *first, const char *second);

#endif
