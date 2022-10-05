/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:19:38 by stapioca          #+#    #+#             */
/*   Updated: 2022/10/03 22:47:11 by njohanne         ###   ########.fr       */
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
		j = 0;
		while (g_sh.res_pars[i][j])
		{
			free(g_sh.res_pars[i][j]);
			j++;
		}
		free(g_sh.res_pars[i]);
		i++;
	}
	free(g_sh.res_pars);
	printf("free_g_sh: res_pars free.\n");
}

void	free_g_sh(void)
{
	//print_arr_g_sh_res_pars();
	free(g_sh.str);
	free_g_sh_res_pars();
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
	i = 0;
	while (g_sh.env[i])
		free(g_sh.env[i++]);
	free(g_sh.env);
	printf("free_g_sh: env free.\n");
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
