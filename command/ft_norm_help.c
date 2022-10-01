/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:01:35 by njohanne          #+#    #+#             */
/*   Updated: 2022/10/01 16:10:23 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_norm_help(char **env, char **arv)
{
	int		i;
	int		len;
	char	**nenv;

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
	return (nenv);
}
