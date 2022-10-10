/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:19:38 by stapioca          #+#    #+#             */
/*   Updated: 2022/10/08 17:10:55 by vlad             ###   ########.fr       */
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
}

void	free_g_sh(void)
{
	free(g_sh.str);
	free_g_sh_res_pars();
}

void	free_and_exit(int err_nb)
{
	int	i;

	if (err_nb != 0)
		free_g_sh();
	i = 0;
	while (g_sh.commands[i])
		free(g_sh.commands[i++]);
	free(g_sh.commands);
	i = 0;
	while (g_sh.env[i])
		free(g_sh.env[i++]);
	free(g_sh.env);
	if (err_nb == 0)
	{
		exit(0);
	}
	if (err_nb == 1)
	{
		exit(-1);
	}
}
