/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auferran <auferran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:15:11 by auferran          #+#    #+#             */
/*   Updated: 2023/09/16 20:04:45 by auferran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

typedef struct s_lst_arg
{
	char		*arg;
	struct		s_lst_arg *next;
}				t_lst_arg;

typedef struct s_lst_hd
{
	char		*limiter;
	struct		s_lst_hd *next;
}				t_lst_hd;

typedef struct s_lst_file
{
	char		*infile;
	char		*outfile;
	int			outfile_type;
	struct		s_lst_file *next;
}				t_lst_file;

typedef struct s_lst_cmd
{
	char		*name;
	struct		s_lst_arg *arg;
	struct		s_lst_hd *heredoc;
	struct		s_lst_files *file;
	struct		s_lst_cmd *next;
}				t_lst_cmd;

void	error(char *str);

void	free_all(char **prompt, t_lst_cmd **cmd);

void		minishell(char **env);
int			manage_sig(void);

int			ft_strlen(char *str);
void		*ft_memset(void *pointer, int value, size_t count);
int			ft_strcmp(const char *first, const char *second);

int			init_lst(char *prompt, t_lst_cmd **cmd);
int			check_prompt(char *prompt, t_lst_cmd *cmd);

t_lst_cmd	*ft_lst_new(void);
void		ft_lst_add_back(t_lst_cmd *lst_new, t_lst_cmd **lst);
void		ft_lst_clear(t_lst_cmd **cmd);

#endif
