/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:19:38 by stapioca          #+#    #+#             */
/*   Updated: 2022/09/05 21:06:57 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_g_sh_res_pars(void)
{
	int	i;
	int	j;

	i = 0;
	while (g_sh.res_pars[i])
	{
		printf("free_g_sh_res_pars: i = %d\n", i);
		j = 0;
		while (g_sh.res_pars[i][j])
		{
			printf("free_g_sh_res_pars: j = %d\n", j);
			printf("free_g_sh_res_pars: g_sh.res_pars[%d][%d] = %s\n", i, j, g_sh.res_pars[i][j]);
			free(g_sh.res_pars[i][j]);
			printf("free_g_sh_res_pars: j = %d free done.\n", j);
			j++;
		}
		free(g_sh.res_pars[i]);
		i++;
	}
	// i = 0;
	// while (g_sh.res_pars[i])
	// 	free(g_sh.res_pars[i++]);
	free(g_sh.res_pars);
	printf("free_g_sh: res_pars free.\n");
}

void	free_g_sh(void)
{
	//int	i;
	
	print_arr_g_sh_res_pars();
	free_g_sh_res_pars();
	
	// i = 0;
	// while (g_sh.cmd_and_args[i])
	// 	free(g_sh.cmd_and_args[i++]);
	// free(g_sh.cmd_and_args);
	// printf("free_g_sh: cmd_and_args free.\n");
	
	/*i = 0;
	while (g_sh.env[i])
		free(g_sh.env[i++]);
	free(g_sh.env);
	printf("free_g_sh: env free.\n");*/
	
	printf("free_g_sh: g_sh.str = %s\n", g_sh.str);

	// if (g_sh.str)
	// {
	// 	printf("free_g_sh: str start free..\n");
	// 	free(g_sh.str);
	// 	printf("free_g_sh: str free.\n");
	// }
}

void	free_and_exit(int err_nb)
{
	int	i;

	if (err_nb != 0)
		free_g_sh();
	printf("free_and_exit: 1\n");
	i = 0;
	while (g_sh.commands[i])
		free(g_sh.commands[i++]);
	free(g_sh.commands);
	printf("free_g_sh: commands free.\n");
	if (err_nb == 0)
	{
		printf("free_and_exit: 2\n");
		exit(0);
	}
	if (err_nb == 1)
	{
		printf("minishell: error 1\n");
		exit(-1);
	}
}
