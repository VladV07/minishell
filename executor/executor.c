/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:52:46 by stapioca          #+#    #+#             */
/*   Updated: 2022/10/11 00:39:04 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_executor(char ***res_pars, int *get_command, int *i, int *count)
{
	g_sh.tmpin = dup(0);
	g_sh.tmpout = dup(1);
	g_sh.fd_stdin = dup(g_sh.tmpin);
	*get_command = 0;
	*i = -1;
	*count = 0;
	while (res_pars[++*i] != NULL)
		(*count)++;
	*i = 0;
}

void	do_redir_start(char **res_pars, int *i, int *j, int *count)
{
	g_sh.rd = do_redirections(res_pars);
	dup2(g_sh.fd_stdin, 0);
	close(g_sh.fd_stdin);
	if (*i == (*count - 1))
	{
		if (g_sh.rd == 0 || g_sh.rd == 2)
			g_sh.fd_stdout = dup(g_sh.tmpout);
	}
	else
	{
		pipe(g_sh.fdpipe);
		g_sh.fd_stdout = g_sh.fdpipe[1];
		g_sh.fd_stdin = g_sh.fdpipe[0];
	}
	dup2(g_sh.fd_stdout, 1);
	close(g_sh.fd_stdout);
	*j = 0;
}

void	go_on_commands(char **res_pars, int *j, int *get_command)
{
	while (g_sh.commands[*j])
	{
		if (!g_sh.cmd_and_args[0])
			break ;
		if (ft_strcmp(g_sh.cmd_and_args[0], g_sh.commands[*j]) == 0)
		{
			do_command(res_pars, *j);
			g_sh.err_exit = 0;
			printf("res ft_set_env = %d\n", ft_set_env("QSD", "QGH")); //не работает функция =1
			*get_command = 1;
		}
		(*j)++;
	}
}

void	if_not_in_commands(int *get_command, int *ret)
{
	if (*get_command == 0)
	{
		*ret = fork();
		if (*ret == 0)
		{
			close(g_sh.tmpin);
			close(g_sh.tmpout);
			close(g_sh.fd_stdin);
			if (*get_command == 0)
			{
				execvp(g_sh.cmd_and_args[0], g_sh.cmd_and_args);
				if (errno == 2)
					printf("minishell: %s: command not found\n", \
						g_sh.cmd_and_args[0]);
				else
					perror("execvp");
			}
			free(g_sh.cmd_and_args);
			free_and_exit(1);
		}
		dup2(g_sh.tmpin, 0);
		dup2(g_sh.tmpout, 1);
		waitpid(*ret, NULL, 0);
	}
}

void	executor(char ***res_pars)
{
	int		i;
	int		j;
	int		get_command;
	int		ret;
	int		count;

	init_executor(res_pars, &get_command, &i, &count);
	while (res_pars[i] != NULL)
	{
		do_redir_start(res_pars[i], &i, &j, &count);
		go_on_commands(res_pars[i], &j, &get_command);
		if_not_in_commands(&get_command, &ret);
		free(g_sh.cmd_and_args);
		i++;
	}
	dup2(g_sh.tmpin, 0);
	dup2(g_sh.tmpout, 1);
	close(g_sh.tmpin);
	close(g_sh.tmpout);
}
