/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:52:46 by stapioca          #+#    #+#             */
/*   Updated: 2022/08/21 21:49:38 by stapioca         ###   ########.fr       */
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

char	**split_redirections(char **res_pars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	free(g_sh.cmd_and_args[0]);
	free(g_sh.cmd_and_args[1]);
	free(g_sh.cmd_and_args);
	g_sh.cmd_and_args = malloc(10000);
	while (res_pars[i])
	{
		printf("res_pars[%d]= %s\n", i, res_pars[i]);
		if (strcmp(res_pars[i], "<") == 0) // заменить на ft_strcmp
		{
			j = -1;
			while (++j < i)
				g_sh.cmd_and_args[j] = res_pars[j];
			g_sh.cmd_and_args[j] = NULL;
			g_sh.redirect = ft_strdup("<");
			j = 0;
			g_sh.plase_redirect = i + 1;
			//res_pars = res_pars + i + 1;
			break ;
		}
		if (strcmp(res_pars[i], "<<") == 0) // заменить на ft_strcmp
		{
			j = -1;
			while (++j < i)
				g_sh.cmd_and_args[j] = res_pars[j];
			g_sh.cmd_and_args[j] = NULL;
			g_sh.redirect = ft_strdup("<<");
			g_sh.plase_redirect = i + 1;
			//res_pars = res_pars + i + 1;
			break ;
		}
		if (strcmp(res_pars[i], ">") == 0) // заменить на ft_strcmp
		{
			j = -1;
			while (++j < i)
				g_sh.cmd_and_args[j] = res_pars[j];
			g_sh.cmd_and_args[j] = NULL;
			g_sh.redirect = ft_strdup(">");
			g_sh.plase_redirect = i + 1;
			//res_pars = res_pars + i + 1;
			break ;
		}
		if (strcmp(res_pars[i], ">>") == 0) // заменить на ft_strcmp
		{
			j = -1;
			while (++j < i)
				g_sh.cmd_and_args[j] = res_pars[j];
			g_sh.cmd_and_args[j] = NULL;
			g_sh.redirect = ft_strdup(">>");
			g_sh.plase_redirect = i + 1;
			//res_pars = res_pars + i + 1;
			break ;
		}
		if (res_pars[i + 1] == NULL)
		{
			j = -1;
			while (++j <= i)
				g_sh.cmd_and_args[j] = res_pars[j];
			g_sh.cmd_and_args[j] = NULL;
		}
		g_sh.plase_redirect = 0;
		g_sh.redirect = NULL;
		i++;
	}
	return (res_pars);
}

void	executor(char ***res_pars, char **env)
{
	int		i;
	int		j;
	int		get_command;

	(void)env;
	get_command = 0;
	i = 0;
	g_sh.cmd_and_args = malloc(10000); // посчитать выделение памяти
	while (res_pars[i])
	{
		// {{echo}, {123}, {<}, {123}}
		res_pars[i] = split_redirections(res_pars[i]);
		print_arr_g_sh_cmd_and_args();
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
		res_pars[i] = res_pars[i] + g_sh.plase_redirect;
		//i = g_sh.plase_redirect - 1;
		if (!g_sh.redirect)
			i++;
		//print_arr_g_sh_cmd_and_args();
	}
}
