/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_cpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:07:54 by njohanne          #+#    #+#             */
/*   Updated: 2022/10/01 15:20:58 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_unset_cpy(char	*str, char **nenv)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (g_sh.env[++i])
	{
		if (ft_strcmp(g_sh.env[i], str) != 0)
		{
			nenv[++j] = (char *)malloc(sizeof(char *) * ft_strlen(g_sh.env[i]));
			nenv[j] = memcpy(nenv[j], g_sh.env[i], ft_strlen(g_sh.env[i]));
		}
	}
	return (nenv);
}
