#include "pipex.h"
#include "minishell.h"

int	doublon_var_content(char *str, t_lst_env *lst_env)
{
	int	i;

	while (lst_env)
	{
		i = 0;
		while (lst_env->line[i] && str[i])
		{
			if (lst_env->line[i] != str[i])
				break ;
			i++;
		}
		if (!lst_env->line[i] && !str[i])
			return (1);
		lst_env = lst_env->next;
	}
	return (0);
}

char	*replace_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	line = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!line)
		return (error("MALLOC FALURE\n"), NULL);
	while (str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

int	doublon_var(char *str, t_lst_env **lst_env)
{
	int			i;
	t_lst_env	*tmp;

	tmp = *lst_env;
	while (tmp)
	{
		i = 0;
		while (tmp->line[i] && str[i] && tmp->line[i] != '=')
		{
			if (tmp->line[i] != str[i])
				break ;
			i++;
		}
		if (tmp->line[i] && tmp->line[i] == '=')
		{
			printf("coucou\n");
			free(tmp->line);
			printf("%s\n", str);
			tmp->line = replace_line(str);
			printf("%s\n", tmp->line);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	push_env(char *str, t_lst_env **lst_env)
{
	if (doublon_var_content(str, *lst_env))
	{
		printf("doublon var content! \n");
		return ;
	}
	if (doublon_var(str, lst_env))
	{
		printf("doublon var");
	}
}

void	builtins_export(char **argv, t_struct_env *s)
{
	int	i;

	i = 1;
	if (!argv[i])
	{
		print_export(s->lst_export);
		return ;
	}
	if (its_option(argv))
		return ;
	while (argv[i])
	{
		if (its_valid(argv[i]))
		{
			if (check_egal(argv[i]))
				push_env(argv[i], &s->lst_env);
			//else
			//	push_export(argv[i], &s->lst_export);
		}
		i++;
	}
}
