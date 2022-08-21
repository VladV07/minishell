/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:52:46 by stapioca          #+#    #+#             */
/*   Updated: 2022/08/21 17:47:33 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	executor(char ***res_pars, char **env)
{
	int	i;
	int	j;
	int	get_command;

	(void)env;
	get_command = 0;
	i = 0;
	while (res_pars[i])
	{
		j = 0;
		while (g_sh.commands[j])
		{
			printf("res_pars[i][0]= %s\n", res_pars[i][0]);
			printf("g_sh.commands[j]= %s\n", g_sh.commands[j]);
			if (strcmp(res_pars[i][0], g_sh.commands[j]) == 0)
			{
				printf("comand= %s\n", g_sh.commands[j]);
				get_command = 1;
			}
			j++;
		}
		if (get_command == 0)
			printf("minishell: %s: command not found\n", res_pars[i][0]);
		i++;
	}
}
