/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_in_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:24:11 by stapioca          #+#    #+#             */
/*   Updated: 2022/08/10 18:46:06 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <string.h>  // потом убрать

char	*get_in_env(char *str, int *i, char **env)
{
	int		nb_dollar;
	int		j;
	char	*key;
	char	*tmp;

	nb_dollar = *i;
	while (str[*i] != '\0')
	{
		(*i)++;
		if (!is_key(str[*i]))
			break ;
	}
	if (*i == nb_dollar + 1)
		return (str);
	key = ft_substr(str, nb_dollar + 1, *i - nb_dollar - 1);
	j = -1;
	while (env[++j])
	{
		if (strstr(env[j], key)) //нет в библиотеке ft_ 
		{
			tmp = ft_substr(env[j], 0, ln_env(env[j]));
			if (strcmp(key, tmp) == 0) //нет в библиотеке ft_ 
				break ;
		}
	}
	tmp = ft_substr(env[j], ln_env(env[j]) + 1, ft_strlen(env[j]) - ln_env(env[j]));
	return (tmp);
}
