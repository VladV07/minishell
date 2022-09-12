/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:52:46 by stapioca          #+#    #+#             */
/*   Updated: 2022/09/12 18:45:27 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_arr_g_sh_cmd_and_args(void)
{
	int	i;

	i = 0;
	while (g_sh.cmd_and_args[i] != NULL)
	{
		printf("g_sh.cmd_and_args[%d]=%s\n", i, g_sh.cmd_and_args[i]);
		i++;
	}
}


void	do_command(char **cmd_and_args, int nb_command)
{
	(void)cmd_and_args;
	if (nb_command == 0)
		g_sh.err_exit = ft_echo(cmd_and_args);
	// if (nb_command == 1)
	// 	cd(cmd_and_args);
	if (nb_command == 2)
		ft_pwd();
	if (nb_command == 3)
		ft_export(cmd_and_args);
	// if (nb_command == 4)
	// 	unset(cmd_and_args);
	if (nb_command == 5)
		ft_env();
	if (nb_command == 6)
		g_sh.stop_flag = 1;
}

int	do_redirections(char **res_pars)
{
	int	i;
	int	j;
	int	rd_in;
	int	rd_out;

	i = 0;
	while (res_pars[i])
		i++;
	g_sh.cmd_and_args = (char **)malloc(sizeof(char *) * (i + 1));
	// i = 0;
	// while (res_pars[i])
	// {
	// 	j = 0;
	// 	while (res_pars[i][j])
	// 		j++;
	// 	g_sh.cmd_and_args[i] = (char *)malloc(sizeof(char) * j);
	// 	i++;
	// }
	
	//if (!g_sh.cmd_and_args)
	//	exit_err;
	i = 0;
	j = 0;
	rd_in = 0;
	rd_out = 0;
	while (res_pars[i])
	{
		if (strcmp(res_pars[i], ">") == 0) //
		{
			g_sh.fd_stdout = open(res_pars[++i], O_WRONLY | O_CREAT | O_TRUNC, 0664);
			rd_out = 1;
		}
		else if (strcmp(res_pars[i], ">>") == 0) //
		{
			g_sh.fd_stdout = open(res_pars[++i], O_WRONLY | O_CREAT | O_APPEND, 0664);
			rd_out = 1;
		}
		else if (strcmp(res_pars[i], "<") == 0) //
		{
			g_sh.fd_stdin = open(res_pars[++i], O_RDONLY, 0664);
			rd_in = 1;
		}
		else if (strcmp(res_pars[i], "<<") == 0) //
		{
			g_sh.fd_stdin = open(res_pars[++i], O_RDONLY, 0664);
			rd_in = 1;
		}
		else
		{
			g_sh.cmd_and_args[j] = res_pars[i];
			j++;
		}
		i++;
	}
	g_sh.cmd_and_args[j] = NULL;
	if (rd_in == 1 && rd_out == 1)
		return (3);
	if (rd_in == 1 && rd_out == 0)
		return (2);
	if (rd_in == 0 && rd_out == 1)
		return (1);
	return (0);
}

void	executor(char ***res_pars, char **env)
{
	int		i;
	int		j;
	int		get_command;
	int		ret;
	int		count;
	int		tmpin;
	int		tmpout;
	int		fdpipe[2];
	int		rd;

	print_arr_g_sh_res_pars();

	(void)env;
	tmpin = dup(0);
	tmpout = dup(1);
	g_sh.fd_stdin = dup(tmpin);
	get_command = 0;

	i = -1;
	count = 0;
	while (res_pars[++i] != NULL)
		count++;
	printf("executor: count= %d\n", count);
	i = 0;
	while (res_pars[i] != NULL)
	{
		printf("res_pars[%d]= %s\n", i, res_pars[i][0]);
		rd = do_redirections(res_pars[i]);
		dup2(g_sh.fd_stdin, 0);
		close(g_sh.fd_stdin);

		if (i == (count - 1))
		{
			if (rd != 3 && rd != 1)
				g_sh.fd_stdout = dup(tmpout);
		}
		else
		{
			pipe(fdpipe);
			g_sh.fd_stdout = fdpipe[1];
			g_sh.fd_stdin = fdpipe[0];
		}

		dup2(g_sh.fd_stdout, 1);
		close(g_sh.fd_stdout);
		j = 0;
		get_command = 0;
		while (g_sh.commands[j])
		{
			if (strcmp(g_sh.cmd_and_args[0], g_sh.commands[j]) == 0) // потом поменять на ft_strcmp
			{
				printf("command= %s, j = %d\n", g_sh.commands[j], j);
				do_command(res_pars[i], j);
				get_command = 1;
			}
			j++;
		}
		if (get_command == 0)
		{
			ret = fork();
			if (ret == 0)
			{
				close(tmpin);
				close(tmpout);
				close(g_sh.fd_stdin);
				if (get_command == 0)
				{
					execvp(g_sh.cmd_and_args[0], g_sh.cmd_and_args);
					if (errno == 2)
						printf("minishell: %s: command not found\n", g_sh.cmd_and_args[0]);
					else
						perror("execvp");
				}
				free(g_sh.cmd_and_args);
				free_and_exit(1);
			}
			dup2(tmpin, 0);
			dup2(tmpout, 1);
			waitpid(ret, NULL, 0);
		}
		// int ii;
		// ii = 0;
		// while (g_sh.cmd_and_args[ii])
		// 	free(g_sh.cmd_and_args[ii++]);
		
		free(g_sh.cmd_and_args);
		i++;
	}
	close(tmpin);
	close(tmpout);
}
