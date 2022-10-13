/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_in_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:24:11 by stapioca          #+#    #+#             */
/*   Updated: 2022/10/13 19:34:17 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*go_on_env(char **env, char *key)
{
	int		j;
	char	*tmp;

	j = -1;
	while (env[++j])
	{
		if (ft_strstr(env[j], key))
		{
			tmp = ft_substr(env[j], 0, ln_env(env[j]));
			if (ft_strcmp(key, tmp) == 0)
			{
				tmp = ft_substr(env[j], ln_env(env[j]) + 1, \
						ft_strlen(env[j]) - ln_env(env[j]));
				return (tmp);
			}
		}
	}
	tmp = ft_strdup("");
	return (tmp);
}

char	*get_in_env(char *str, int *i, char **env)
{
	int		nb_dollar;
	char	*key;
	char	*tmp;

	nb_dollar = *i;
	(*i)++;
	while (str[*i] != '\0' && str[*i] != '$' && str[*i] != ' ' \
						&& str[*i] != '\'' && str[*i] != '\"')
	{
		if (!is_key(str[*i]))
			break ;
		(*i)++;
	}
	if (*i == nb_dollar + 1)
		return (str);
	key = ft_substr(str, nb_dollar + 1, *i - nb_dollar - 1);
	tmp = go_on_env(env, key);
	return (tmp);
}
