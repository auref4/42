#include "pipex.h"
#include "minishell.h"

void	print_env(t_lst_env *env)
{
	while (env)
	{
		printf("%s\n", env->line);
		env = env->next;
	}
	printf("end\n");
}

int	valid_unset(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalpha(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	lets_unset_env(char *str, t_struct_env *s)
{
	int			i;
	t_lst_env	*tmp;
	t_lst_env	*swap;

	tmp = s->lst_env;
	while (tmp)
	{
		i = 0;
		while (str[i] && tmp->line[i] && tmp->line[i] != '='
		&& str[i] == tmp->line[i])
			i++;
		if (!str[i] && tmp->line[i] == '=')
		{
			printf("line = %s\n", tmp->line);
			free(tmp->line);
			swap = tmp->next;
			free(tmp);
			tmp = swap;
			return ;
		}
		tmp = tmp->next;
	}
}

void	lets_unset_export(char *str, t_struct_env *s)
{
	int			i;
	int			j;
	t_lst_env	*tmp;
	t_lst_env	*swap;

	tmp = s->lst_export;
	while (tmp)
	{
		i = 0;
		j = 11;
		while (str[i] && tmp->line[j] && tmp->line[j] != '='
		&& str[i] == tmp->line[j])
		{
			i++;
			j++;
		}
		if (!str[i] && tmp->line[j] == '=')
		{
			printf("line = %s\n", tmp->line);
			free(tmp->line);
			swap = tmp->next;
			free(tmp);
			tmp = swap;
			return ;
		}
		tmp = tmp->next;
	}
}

int	builtins_unset(char	**argv, t_struct_env *s)
{
	int	i;

	if (its_option(argv))
		return (1);
	i = 1;
	while (argv[i])
	{
		if (valid_unset(argv[i]))
		{
			lets_unset_env(argv[i], s);
			lets_unset_export(argv[i], s);
		}
		i++;
	}
	printf("coucou\n");
	print_env(s->lst_env);
	printf("coucou1\n");
	print_env(s->lst_export);
	printf("coucou2\n");
	return (1);
}
