/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 22:29:39 by njohanne          #+#    #+#             */
/*   Updated: 2022/10/01 15:30:27 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_sort_env(char **senv)
{
	char	*str;
	int		k;
	int		i;
	int		sr;

	i = 0;
	sr = 0;
	while (1)
	{
		k = ft_strcmp(senv[i], senv[i + 1]);
		if (k > 0)
		{
			str = senv[i];
			senv[i] = senv[i + 1];
			senv[i + 1] = str;
			sr++;
		}
		if (!senv[++i + 1] && sr == 0)
			return (senv);
		else if (!senv[i + 1])
		{
			sr = 0;
			i = 0;
		}
	}
}

int	ft_print_env(void)
{
	char	**senv;
	int		len;
	int		i;

	len = ft_len_env(g_sh.env);
	senv = (char **)malloc(sizeof(char **) * (len + 1));
	senv[len] = NULL;
	i = -1;
	while (g_sh.env[++i])
	{
		len = ft_strlen(g_sh.env[i]);
		senv[i] = (char *)malloc(sizeof(char *) * len);
		senv[i] = ft_memcpy(senv[i], g_sh.env[i], len);
	}
	senv = ft_sort_env(senv);
	i = -1;
	while (senv[++i])
		printf("%s\n", senv[i]);
	ft_free_env(senv);
	return (0);
}
