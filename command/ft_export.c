/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:55:17 by njohanne          #+#    #+#             */
/*   Updated: 2022/09/17 18:31:35 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_env_join(char **env, char **arv)
{
	char	**nenv;
	int		i;
	int		j;
	int		len;

	i = -1;
	j = 0;
	len = ft_len_env(env) + ft_len_env(arv);
	nenv = (char **)malloc(sizeof(char **) * len);
	nenv[len] = NULL;
	while (env[++i])
	{
		nenv[i] = (char *)malloc(sizeof(char *) * ft_strlen(env[i]));
		nenv[i] = ft_memcpy(nenv[i], env[i], ft_strlen(env[i]));
	}
	i--;
	while (arv[++j])
	{
		nenv[++i] = (char *)malloc(sizeof(char *) * strlen(arv[j]));
		nenv[i] = ft_memcpy(nenv[i], arv[j], ft_strlen(arv[j]));
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
