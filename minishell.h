/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:26:19 by stapioca          #+#    #+#             */
/*   Updated: 2022/10/13 21:36:34 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"
//# include <string.h>  // потом убрать
# include <signal.h>

typedef struct s_data{
	char		**commands;
	char		*str;
	char		***res_pars;
	char		**env;
	char		**cmd_and_args;
	int			fd_stdin;
	int			fd_stdout;
	int			stop_flag;
	int			plase_redirect;
	int			err_exit;
	char		*for_export[3];
	int			tmpin;
	int			tmpout;
	int			fdpipe[2];
	int			rd;
}	t_data;

extern t_data	g_sh;

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
void	executor(char ***res_pars);
void	free_and_exit(int err_nb);
void	free_g_sh(void);
void	print_arr_g_sh_res_pars(void); // для проверки убрать
void	print_arr_g_sh_cmd_and_args(void); // для проверки убрать
void	ctrl_c(int val);
void	ctrl_d(void);

int		ft_strcmp(char *str1, char *str2);
int		ft_strcmp_unequals(char *str1, char *str2);
void	ft_free_env(char **env);
char	*ft_get_env(char *str);
int		ft_set_env(char *c, char *var);
int		ft_echo(char **str);
int		ft_pwd(void);
int		ft_export(char **cmd_and_args);
int		ft_env(void);
int		ft_len_env(char **env);
int		ft_unset(char **cmd_and_args);
int		ft_cd(char **str);
int		ft_exit(char **str);

int		ft_search(int equals, char *str);
int		ft_equals(char *str);
int		ft_print_env(void);
char	**ft_unset_cpy(char	*str, char **nenv);
char	**ft_norm_help(char **env, char *arv);

int		do_herdog(char *res_pars);
int		do_redirections(char **res_pars);
void	do_command(char **cmd_and_args, int nb_command);
char	*ft_strstr(const char *s1, const char *s2);

#endif