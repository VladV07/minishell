/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:02:16 by njohanne          #+#    #+#             */
/*   Updated: 2022/10/13 21:35:45 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_lenenv(char **str)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] == '=')
				len++;
		}
	}
	return (len);
}

char	**ft_cpyenv(char **str, char **nenv)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] == '=')
			{
				nenv[++k] = (char *)malloc(sizeof(char *) * ft_strlen(str[i]));
				nenv[k] = ft_memcpy(nenv[k], str[i], ft_strlen(str[i]));
			}
		}
	}
	return (nenv);
}

int	ft_env(void)
{
	char	**nenv;
	int		i;

	i = -1;
	nenv = (char **)malloc(sizeof(char **) * ft_lenenv(g_sh.env) + 1);
	nenv[ft_lenenv(g_sh.env)] = NULL;
	ft_cpyenv(g_sh.env, nenv);
	while (nenv[++i])
		printf("%s\n", nenv[i]);
	free (nenv);
	return (0);
}
