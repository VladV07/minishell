/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:26:19 by stapioca          #+#    #+#             */
/*   Updated: 2022/09/17 18:34:19 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <sys/errno.h>
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
	char		**commands;
	char		*str;
	char		***res_pars;
	char		**env;
	char		**cmd_and_args;
	int			fd_stdin;
	int			fd_stdout;
	t_execut	*ex_list;
	t_list		env_list;
	int			stop_flag;
	int			plase_redirect;
	int			err_exit;
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
void	free_and_exit(int err_nb);
void	free_g_sh(void);
void	print_arr_g_sh_res_pars(void); // для проверки убрать
int		ft_strcmp(char *str1, char *str2);
int		ft_strcmp_unequals(char *str1, char *str2);
void	ft_free_env(char **env);
int		ft_echo (char **str);
int		ft_pwd(void);
void	ft_export(char **cmd_and_args);
void	ft_env(void);
int		ft_len_env(char **env);
int		ft_unset(char **cmd_and_args);

#endif