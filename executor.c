/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:52:46 by stapioca          #+#    #+#             */
/*   Updated: 2022/08/22 20:10:07 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
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

void	executor(char ***res_pars, char **env)
{
	int		i;
	int		j;
	int		count;
	int		get_command;

	(void)env;
	get_command = 0;
	i = 0;
	count = 0;
	g_sh.ex_list = malloc(sizeof(t_execut) * 10); // посчитать выделение памяти
	while (res_pars[i])
	{
		res_pars[i] = split_redirections(res_pars[i], count);
	/*
		printf("g_sh.redirect= %s\n", g_sh.redirect);
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
			printf("minishell: %s: command not found\n", g_sh.cmd_and_args[0]);
	*/
		res_pars[i] = res_pars[i] + g_sh.plase_redirect;
		if (!g_sh.ex_list[count].redirect)
			i++;
		count++;
	}

	i = 0;
	while (i < count)
	{
		j = 0;
		while (g_sh.ex_list[i].cmd_and_args[j])
		{
			printf("cmd_and_args[%d][%d]= %s\n", i, j, g_sh.ex_list[i].cmd_and_args[j]);
			j++;
		}
		printf("redirect[%d]= %s\n", i, g_sh.ex_list[i].redirect);
		i++;
	}
}
