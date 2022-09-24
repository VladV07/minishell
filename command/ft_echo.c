/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:04:53 by njohanne          #+#    #+#             */
/*   Updated: 2022/09/25 00:21:47 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_echo(char **str)
{
	int	i;
	int	n;

	i = 1;
	n = 1;
	if (!g_sh.cmd_and_args[1])
		return (0);
	while (ft_strcmp(str[i], "-n") == 0)
	{
		n = 0;
		i++;
	}
	while (g_sh.cmd_and_args[i] != NULL)
	{
		printf("%s", g_sh.cmd_and_args[i]);
		if (g_sh.cmd_and_args[++i])
			printf(" ");
	}
	if (n == 1)
		printf("\n");
	printf("!!!!!!!!!!!!!!!!!!!!echo!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	return (0);
}
