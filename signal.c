/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:45:46 by njohanne          #+#    #+#             */
/*   Updated: 2022/10/05 17:10:58 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_c(int val)
{
	(void)val;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ctrl_d(void)
{
	printf("exit\n");
	g_sh.stop_flag = 1;
	ft_free_env(g_sh.env);
	free(g_sh.commands);
	exit(0);
}
