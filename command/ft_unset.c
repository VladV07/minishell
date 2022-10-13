/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:02:38 by njohanne          #+#    #+#             */
/*   Updated: 2022/10/13 19:39:35 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_len_uns(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	return (i);
}

int	ft_equals(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '=')
			return (0);
	}
	return (1);
}

char	**ft_work_nenv(char **nenv, int equals, char *str)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (equals == 0)
		nenv = ft_unset_cpy(str, nenv);
	else
	{
		printf("\n\n\n\n");
		while (g_sh.env[++i])
		{
			if (ft_strcmp_unequals(g_sh.env[i], str) != 0)
			{
				printf("%s\n\n", g_sh.env[i]);
				nenv[++j] = (char *)malloc(sizeof(char) \
					* ft_strlen(g_sh.env[i]));
				nenv[j] = ft_memcpy(nenv[j], g_sh.env[i], \
					ft_strlen(g_sh.env[i]));
			}
		}
	}
	return (nenv);
}

int	ft_search(int equals, char *str)
{
	int	i;

	i = -1;
	if (equals == 0)
	{
		while (g_sh.env[++i])
		{
			if (ft_strcmp(g_sh.env[i], str) == 0)
				return (0);
		}
	}
	else
	{
		while (g_sh.env[++i])
		{
			printf("%s\n\n", g_sh.env[i]);
			if (ft_strcmp_unequals(g_sh.env[i], str) == 0)
				return (0);
		}
	}
	return (1);
}

int	ft_unset(char **cmd_and_args)
{
	int		len;
	int		equals;
	char	**nenv;

	if (!cmd_and_args[1])
		return (1);
	equals = ft_equals(cmd_and_args[1]);
	if (ft_search(equals, cmd_and_args[1]) == 1)
		return (1);
	len = ft_len_env(g_sh.env);
	nenv = (char **)malloc(sizeof(char *) * len);
	nenv[len] = NULL;
	nenv = ft_work_nenv(nenv, equals, cmd_and_args[1]);
	ft_free_env(g_sh.env);
	g_sh.env = nenv;
	return (0);
}
