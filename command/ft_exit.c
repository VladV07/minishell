/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:54:22 by njohanne          #+#    #+#             */
/*   Updated: 2022/10/05 16:44:44 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_vot_exit(int var, int len)
{
	if (var == len || var == 0)
	{
		g_sh.stop_flag = 1;
		return (0);
	}
	else
		return (1);
}

int	ft_valid_param(char **str)
{
	int	i;
	int	j;
	int	var;
	int	len;
	int	pr;

	var = 0;
	pr = 0;
	i = 0;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if ((ft_isdigit(str[i][j])) && pr == var)
				var++;
		}
		pr = var;
	}
	len = ft_len_env(str) - 1;
	return (ft_vot_exit(var, len));
}

int	ft_exit(char **str)
{
	if (!str[1] || (str[1] && !str[2]))
	{
		g_sh.stop_flag = 1;
		return (0);
	}
	if (ft_valid_param(str))
		return (1);
	return (0);
}
