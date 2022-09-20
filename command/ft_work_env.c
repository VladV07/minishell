/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 03:22:51 by njohanne          #+#    #+#             */
/*   Updated: 2022/09/20 06:40:22 by njohanne         ###   ########.fr       */
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

int	ft_set_env(char *c, char *var)
{
	int		i;
	char	**envst;
	char	*str;
	
	i = -1;
	str = (char *)malloc(sizeof(char *));
	str[0] = '\0';
	while (g_sh.env[++i])
	{
		envst = ft_split(g_sh.env[i], '=');
		if (ft_strcmp(envst[0], var) == 0)
		{
			ft_free_env(envst);
			break ;
		}
		ft_free_env(envst);
	}
	if (g_sh.env[i] == NULL)
		return (1);
	free(g_sh.env[i]);
	str = ft_strjoin_free(str, var);
	str = ft_strjoin_free(str, "=");
	str = ft_strjoin_free(str, c);
	g_sh.env[i] = str;
	return (0);
}
