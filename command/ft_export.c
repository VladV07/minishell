/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:55:17 by njohanne          #+#    #+#             */
/*   Updated: 2022/09/29 20:16:56 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_search_nvar(char **env, char *str)
{
	int		i;
	int		j;
	int		len;
	char	*var;

	i = -1;
	len = 0;
	while (str[++i] != '=' && str[i] != '\0')
		len++;
	var = (char *)malloc(sizeof(char *) * (len + 1));
	var[len] = '\0';
	var = ft_memcpy(var, str, len);
	i = -1;
	while (env[++i])
	{
		j = 0;
		while (env[i][j] == var[j])
		{
			if((env[i][j + 1] == '=' || env[i][j + 1] == '\0') && j == len)
			{
				free(var);
				return (0);
			}
			j++;
		}
	}	
	free(var);
	return(1);
}

int	ft_tyt_nax(char *env, char *arv)
{
	int	i;

	i = 0;
	while (env[i] == arv[i])
	{
		if ((env[i + 1] == '=' || env[i + 1] == '\0') && (arv[i + 1] == '\0' || arv[i + 1] == '='))
			return(1);
		i++;
	}
	return(0);
}

char	**ft_env_join(char **env, char **arv)
{
	char	**nenv;
	int		i;
	int		len;

	i = -1;
	if (!ft_search_nvar(env, arv[1]))
	{
		len = ft_len_env(env);
		nenv = (char **)malloc(sizeof(char**) * (len + 1));
		nenv[len] = NULL;
		while (env[++i])
		{
			if (!ft_tyt_nax(env[i], arv[1]))
			{
				nenv[i] = (char *)malloc(sizeof(char *) * ft_strlen(env[i]));
				nenv[i] = ft_memcpy(nenv[i], env[i], ft_strlen(env[i]));
			}
			else
			{
				nenv[i] = (char *)malloc(sizeof(char *) * ft_strlen(arv[1]));
				nenv[i] = ft_memcpy(nenv[i], arv[1], ft_strlen(arv[1]));
			}
		}
	}
	else
	{
		len = ft_len_env(env) + 1;
		nenv = (char **)malloc(sizeof(char **) * (len + 1));
		nenv[len] = NULL;
		while (env[++i])
		{
			nenv[i] = (char *)malloc(sizeof(char *) * ft_strlen(env[i]));
			nenv[i] = ft_memcpy(nenv[i], env[i], ft_strlen(env[i]));
		}
		nenv[i] = (char *)malloc(sizeof(char *) * strlen(arv[1]));
		nenv[i] = ft_memcpy(nenv[i], arv[1], ft_strlen(arv[1]));
	}
	ft_free_env(env);
	return (nenv);
}

void	ft_export(char **cmd_and_args)
{
	int	i;

	i = 0;
	if (cmd_and_args[1])
		g_sh.env = ft_env_join(g_sh.env, cmd_and_args);
	else
	{
		while (g_sh.env[i])
			printf("%s\n", g_sh.env[i++]);
	}
	printf("!!!!!!!!!!!!!!!!export!!!!!!!!!!!!!!!!!!!!!!");
}
