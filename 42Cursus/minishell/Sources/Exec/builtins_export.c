#include "pipex.h"
#include "minishell.h"

int	doublon_content(char *str, char *tmp, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tmp[j] && line[j])
		j++;
	while (str[i] && str[i] != '=')
		i++;
	i++;
	while (line[j] && line[j] != '"')
		j++;
	j++;
	while(str[i] && line[j] && line[j] != '"')
	{
		if (str[i] != line[j])
			return (1);
		i++;
		j++;
	}
	if !(str[i] && line[j] == '"')
		return (2);
	return (1);
}

int	doublon_export(char *str, t_lst_env *lst_export, int *replace)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = "declare -x ";
	*replace = 1;
	while (lst_export)
	{
		j = 0;
		i = 0;
		while (tmp[j] && lst_export->line[j])
			j++;
		while (str[i] && lst_export->line[j] && lst_export[j] != '=')
			if (str[i++] != lst_export->line[j++])
				break;
		if (str[i] && str[i] == '=' &&
		lst_export->line[j] && lst_export->line[j] == '=')
		{
			*replace = doublon_content(str, tmp, lst_export->line);
			return (1);
		}
		lst_export = lst_export->next;
	}
	return (0);
}

void	push_export(char *str, t_lst_env **lst_export)
{
	int	replace;

	replace = 0;
	if (doublon_export(str, *lst_export, &replace) && replace == 1)
		return ;
	if (replace == 2)
	{
		delete_line(str, lst_export);
		add_line(str, lst_export);
	}
	else
		add_line(str, lst_export);
	sort_export(lst_export);
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
	if (its_option(argv[i]))
		return ;
	while (argv[i])
	{
		if (its_valid(argv[i]))
		{
			if (check_egal(argv[i]))
			{
				push_env(argv[i], &s->lst_env);
				push_export(argv[i], &s->lst_export)
			}
			else
				push_export(argv[i], &s->lst_export);
		}
		i++;
	}
}
