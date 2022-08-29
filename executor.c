/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:52:46 by stapioca          #+#    #+#             */
/*   Updated: 2022/08/29 21:55:00 by stapioca         ###   ########.fr       */
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

/*
void	do_command(char **cmd_and_args, int nb_command)
{
	if (nb_command == 0)
		echo(cmd_and_args);
	if (nb_command == 1)
		cd(cmd_and_args);
	if (nb_command == 2)
		pwd(cmd_and_args);
	if (nb_command == 3)
		export(cmd_and_args);
	if (nb_command == 4)
		unset(cmd_and_args);
	if (nb_command == 5)
		env(cmd_and_args);
	if (nb_command == 6)
		exit();
}
*/

int	do_split_redirections(char **res_pars, int i, int count, char *redir)
{
	int	j;

	if (strcmp(res_pars[i], redir) == 0) // заменить на ft_strcmp
	{
		j = -1;
		while (++j < i)
			g_sh.ex_list[count].cmd_and_args[j] = res_pars[j];
		g_sh.ex_list[count].cmd_and_args[j] = NULL;
		g_sh.ex_list[count].redirect = ft_strdup(redir);
		j = 0;
		g_sh.plase_redirect = i + 1;
		return (0);
	}
	return (1);
}

void	do_split_redirections_end(char **res_pars, int i, int count)
{
	int	j;

	if (res_pars[i + 1] == NULL)
	{
		j = -1;
		while (++j <= i)
			g_sh.ex_list[count].cmd_and_args[j] = res_pars[j];
		g_sh.ex_list[count].cmd_and_args[j] = NULL;
	}
	g_sh.plase_redirect = 0;
	g_sh.ex_list[count].redirect = NULL;
}

char	**split_redirections(char **res_pars, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	g_sh.ex_list[count].cmd_and_args = malloc(1000); // посчитать выделение памяти
	g_sh.ex_list[count].redirect = malloc(10); // посчитать выделение памяти
	while (res_pars[i])
	{
		printf("res_pars[%d]= %s\n", i, res_pars[i]);
		if (do_split_redirections(res_pars, i, count, "<") == 0)
			break ;
		if (do_split_redirections(res_pars, i, count, "<<") == 0)
			break ;
		if (do_split_redirections(res_pars, i, count, ">") == 0)
			break ;
		if (do_split_redirections(res_pars, i, count, ">>") == 0)
			break ;
		do_split_redirections_end(res_pars, i, count);
		i++;
	}
	return (res_pars);
}

void	do_redirections(char **res_pars)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	printf("do_redirections: 1\n");
	free(g_sh.cmd_and_args);
	printf("do_redirections: 2\n");
	//g_sh.fd_stdin = dup(0);
	//g_sh.fd_stdout = dup(1);

	i = 0;
	count = 0;
	while (res_pars[i])
	{
		j = 0;
		while (res_pars[i][j])
		{
			j++;
		}
		i++;
		count = count + j + 1;
	}
	printf("do_redirections: 4\n");
	g_sh.cmd_and_args = malloc(count);
	printf("do_redirections: 5\n");
	//if (!g_sh.cmd_and_args)
	//	exit_err;
	i = 0;
	j = 0;
	while (res_pars[i])
	{
		printf("do_redirections: res_pars[%d]= %s\n", i, res_pars[i]);
		if (strcmp(res_pars[i], ">") == 0)
			g_sh.fd_stdin = open(res_pars[++i], O_WRONLY | O_CREAT | O_TRUNC, 0664);
		else if (strcmp(res_pars[i], ">>") == 0)
			g_sh.fd_stdin = open(res_pars[++i], O_WRONLY | O_CREAT | O_APPEND, 0664);
		else if (strcmp(res_pars[i], "<") == 0)
			g_sh.fd_stdout = open(res_pars[++i], O_RDONLY, 0664);
		else if (strcmp(res_pars[i], "<<") == 0)
			g_sh.fd_stdout = open(res_pars[++i], O_RDONLY, 0664);
		else
		{
			g_sh.cmd_and_args[j] = res_pars[i];
			printf("do_redirections: g_sh.cmd_and_args[%d]= %s\n", j, g_sh.cmd_and_args[j]);
			j++;
		}
		i++;
	}
	printf("do_redirections: 6\n");
	g_sh.cmd_and_args[j] = NULL;
	printf("do_redirections: 7\n");
	//dup2(g_sh.fd_stdin, 0);
	printf("do_redirections: 8\n");
	//dup2(g_sh.fd_stdout, 1);
	printf("do_redirections: 9\n");
}

void	executor(char ***res_pars, char **env)
{
	int		i;
	int		j;
	int		get_command;
	int		ret;
	int		fdpipe[2];
	int		count;

	(void)env;
	g_sh.fd_stdin = dup(0);
	g_sh.fd_stdout = dup(1);
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
		printf("executor: 1\n");
		//do_redirections(res_pars[i]);
		printf("executor: 2\n");
		
		if (i != (count - 1))
		{
			printf("executor: 3\n");
			pipe(fdpipe);
			g_sh.fd_stdin = fdpipe[0];
			g_sh.fd_stdout = fdpipe[1];
			printf("executor: 4\n");
		}
		dup2(g_sh.fd_stdin, 0);
		close(g_sh.fd_stdin);
		do_redirections(res_pars[i]);
		//dup2(g_sh.fd_stdin, 0);
		dup2(g_sh.fd_stdout, 1);
		printf("executor: 5\n");
		//close(g_sh.fd_stdin);
		close(g_sh.fd_stdout);
		printf("executor: 6\n");
		
		ret = fork();
		printf("executor: 3\n");
		if (ret == 0)
		{
			//do_redirections(res_pars[i]);
			printf("executor: 4\n");
			j = 0;
			get_command = 0;
			while (g_sh.commands[j])
			{
				//printf("g_sh.cmd_and_args[0]= %s\n", g_sh.cmd_and_args[0]);
				//printf("g_sh.commands[%d]= %s\n", j, g_sh.commands[j]);
				if (strcmp(g_sh.cmd_and_args[0], g_sh.commands[j]) == 0) // потом поменять на ft_strcmp
				{
					printf("command= %s\n", g_sh.commands[j]);
					//do_command(res_pars[i], j);
					get_command = 1;
				}
				j++;
			}
			if (get_command == 0)
			{
				//execvp("ls", NULL);
				//perror("execvp");
				printf("executor: 5\n");
				//printf("minishell: %s: command not found\n", g_sh.cmd_and_args[0]);
			}
			printf("executor: exit\n");
			close(g_sh.fd_stdin);
			close(g_sh.fd_stdout);
			close(fdpipe[0]);
			close(fdpipe[1]);
			exit(1); // свой exit
		}
		i++;
		printf("executor: 6\n");
		//print_arr_g_sh_cmd_and_args();
		printf("executor: 7\n");
		dup2(g_sh.fd_stdin, 0);
		dup2(g_sh.fd_stdout, 1);
		close(g_sh.fd_stdin);
		close(g_sh.fd_stdout);
		close(fdpipe[0]);
		close(fdpipe[1]);
		waitpid(ret, NULL, 0);
		printf("executor: 8\n");
	}
	printf("executor: 9\n");
}
