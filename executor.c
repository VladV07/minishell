/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:52:46 by stapioca          #+#    #+#             */
/*   Updated: 2022/08/30 22:08:46 by stapioca         ###   ########.fr       */
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

void	do_redirections(char **res_pars)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	printf("do_redirections: 1\n");
	//free(g_sh.cmd_and_args);
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
	//printf("do_redirections: 4\n");
	g_sh.cmd_and_args = malloc(count);
	//printf("do_redirections: 5\n");
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
	//printf("do_redirections: 6\n");
	g_sh.cmd_and_args[j] = NULL;
	printf("do_redirections: 7\n");
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
	int		fdin;
	int		fdout;
	int		fdpipe[2];

	(void)env;
	tmpin = dup(0);
	tmpout = dup(1);
	fdin = dup(tmpin);
	//g_sh.fd_stdin = dup(tmpin);
	//g_sh.fd_stdout = dup(tmpout);
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
		do_redirections(res_pars[i]);
		printf("executor[cmd = %s]: 2\n",g_sh.cmd_and_args[0]);
		dup2(fdin, 0);
		close(fdin);
		if (i == (count - 1))
		{
			fdout = dup(tmpout);
		}
		else
		{
			printf("executor[cmd = %s]: 3\n",g_sh.cmd_and_args[0]);
			pipe(fdpipe);
			fdout = fdpipe[1];
			fdin = fdpipe[0];
			printf("executor[cmd = %s]: fdpipe[0]=%d fdpipe[1]=%d 4\n",g_sh.cmd_and_args[0], fdpipe[0], fdpipe[1]);
		}

		dup2(fdout, 1);
		close(fdout);
		printf("executor[cmd = %s]: 5\n",g_sh.cmd_and_args[0]);
		
		ret = fork();
		printf("executor[cmd = %s]: fdpipe[0]=%d fdpipe[1]=%d 6\n",g_sh.cmd_and_args[0], fdpipe[0], fdpipe[1]);
		if (ret == 0)
		{
			close(tmpin);
			close(tmpout);
			close(fdin);
			//do_redirections(res_pars[i]);
			printf("executor: 7\n");
			j = 0;
			get_command = 0;
			printf("executor[cmd = %s]: fdpipe[0]=%d fdpipe[1]=%d 8\n",g_sh.cmd_and_args[0], fdpipe[0], fdpipe[1]);
			while (g_sh.commands[j])
			{
				printf("executor: while (g_sh.commands[j]) 9\n");
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
				printf("executor[cmd = %s]: fdpipe[0]=%d fdpipe[1]=%d 10execvp\n",g_sh.cmd_and_args[0], fdpipe[0], fdpipe[1]);
				//printf("minishell: %s: command not found\n", g_sh.cmd_and_args[0]);
			}
			printf("executor[cmd = %s]: fdpipe[0]=%d fdpipe[1]=%d 11exit\n",g_sh.cmd_and_args[0], fdpipe[0], fdpipe[1]);
			exit(0); // свой exit
		}
		printf("executor[cmd = %s]: fdpipe[0]=%d fdpipe[1]=%d 12\n",g_sh.cmd_and_args[0], fdpipe[0], fdpipe[1]);
		//print_arr_g_sh_cmd_and_args();
		dup2(tmpin, 0);
		dup2(tmpout, 1);
		//close(tmpin);
		//close(tmpout);
		//g_sh.fd_stdin = dup(fdpipe[1]);
		//close(fdpipe[0]);
		//dup2(tmpin, 0);
		printf("executor[cmd = %s]:  waitpid\n", g_sh.cmd_and_args[0]);
		waitpid(ret, NULL, 0);
		printf("executor[cmd = %s]: fdpipe[0]=%d fdpipe[1]=%d 13\n",g_sh.cmd_and_args[0], fdpipe[0], fdpipe[1]);
		i++;
	}
	printf("executor: 14end\n");
}
