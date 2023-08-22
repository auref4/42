#ifndef MINISHELL_H
#define MINISHELL_H
#define ERROR_MALLOC 0
#define ERROR_PROMPT 1

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

typedef struct t_env_pipex
{
	char	*infile;
	char	*outfile;
	int		open_outfile_type;
	int		heredoc;
	char	*limiter;
	char	**cmd;
}			s_env_pipex;

void	error(int nb);
void	free_all(char *prompt, s_env_pipex *env_pipex);
void	minishell(char **env);
int		manage_sig();
int		ft_strcmp(const char *first, const char *second);
void	*ft_memset(void *pointer, int value, size_t count);
int		init_struct(char *prompt, s_env_pipex *env_pipex);
int		check_prompt(char *prompt, s_env_pipex *env_pipex);

#endif
