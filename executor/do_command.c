/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:06:12 by vlad              #+#    #+#             */
/*   Updated: 2022/10/11 00:06:18 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	g_sh.err_exit = 0;
	if (nb_command == 0)
		g_sh.err_exit = ft_echo(cmd_and_args);
	if (nb_command == 1)
		g_sh.err_exit = ft_cd(cmd_and_args);
	if (nb_command == 2)
		g_sh.err_exit = ft_pwd();
	if (nb_command == 3)
		ft_export(cmd_and_args);
	if (nb_command == 4)
		g_sh.err_exit = ft_unset(cmd_and_args);
	if (nb_command == 5)
		ft_env();
	if (nb_command == 6)
		ft_exit(cmd_and_args);
	if (g_sh.err_exit == 1)
		printf("Command error: %s\n", cmd_and_args[0]);
}
