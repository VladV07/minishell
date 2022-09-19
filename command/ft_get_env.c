/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 03:22:51 by njohanne          #+#    #+#             */
/*   Updated: 2022/09/19 03:24:48 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_env(char *str)
{
	char	**envrd;
	int		i;

	i = -1;
	while (g_sh.env[++i])
	{
		envrd = ft_split(g_sh.env[i], '=');
		if (ft_strcmp(envrd[0], str) == 0)
		{
			ft_free_env(envrd);
			break ;
		}
		ft_free_env(envrd);
	}
	if (g_sh.env[i] == NULL)
		return (NULL);
	return (g_sh.env[i]);
}
