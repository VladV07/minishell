/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:26:19 by stapioca          #+#    #+#             */
/*   Updated: 2022/08/22 19:52:43 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <readline/readline.h>
# include "libft/libft.h"
# include <string.h>  // потом убрать

typedef struct s_list{
	int				data;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_list_executor{
	char					**cmd_and_args;
	char					*redirect;
}	t_execut;

typedef struct s_data{
	char		*commands[8];
	char		*str;
	char		***res_pars;
	char		**env;
	t_execut	*ex_list;
	t_list		env_list;
	int			stop_flag;
	int			plase_redirect;
}	t_data;

t_data	g_sh;

char	*ft_readline(char *p);
char	*ft_strjoin_free(char *s1, char const *s2);
int		is_key(char ch);
int		ln_env(char *env_j);
char	*get_in_env(char *str, int *i, char **env);
char	*get_dollar(char *str, int *i, char **env);
char	*get_quote(char *str, int *i);
char	*get_slesh(char *str, int *i);
char	*get_double_quotes(char *str, int *i, char **env);
void	parser(char *str, char **env);
int		lexer(char *str);
void	executor(char ***res_pars, char **env);

#endif