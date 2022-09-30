/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:55:17 by njohanne          #+#    #+#             */
/*   Updated: 2022/09/30 22:40:58 by njohanne         ###   ########.fr       */
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
			if((env[i][j + 1] == '=' || env[i][j + 1] == '\0') && j == len - 1)
			{
				free(var);
				if (str[len] == '\0')
					return(-1);
				return (i);
			}
			j++;
		}
	}	
	free(var);
	return(0);
}

char	**ft_nenv(char **env, char *str, int i)
{
	int		j;
	int		len;
	char	**nenv;

	j = -1;
	len = ft_len_env(env);
	nenv = (char **)malloc(sizeof(char **) * (len + 1));
	nenv[len] = NULL;
	while (env[++j])
	{
		if (j != i)
		{
			nenv[j] = (char *)malloc(sizeof(char *) * ft_strlen(env[j]));
			nenv[j] = ft_memcpy(nenv[j], env[j], ft_strlen(env[j]));
		}
		else
		{
			nenv[j] = (char *)malloc(sizeof(char *) * ft_strlen(str));
			nenv[j] = ft_memcpy(nenv[j], str, ft_strlen(str));
		}
	}
	free(str);
	return(nenv);
}

char	**ft_env_join(char **env, char **arv)
{
	char	**nenv;
	char	*str;
	int		i;
	int		len;

	i = ft_search_nvar(env, arv[1]);
	if (i > 0)
	{
		len = ft_strlen(arv[1]);
		str = (char *)malloc(sizeof(char *) * (len + 1));
		str[len] = '\0';
		str = ft_memcpy(str, arv[1], len);
		nenv = ft_nenv(env, str, i);
	}
	else if (i < 0)
	{
		printf("AHUET !!!!!!!!!!!!!!! %d !!!!!!!!!\n", i);
		return(env);
	}
	else
	{
		i = -1;
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
	if (cmd_and_args[1])
		g_sh.env = ft_env_join(g_sh.env, cmd_and_args);
	else
		ft_print_env();

	printf("!!!!!!!!!!!!!!!!export!!!!!!!!!!!!!!!!!!!!!!");
}
