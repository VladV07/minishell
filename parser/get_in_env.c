/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_in_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:24:11 by stapioca          #+#    #+#             */
/*   Updated: 2022/09/24 18:01:48 by stapioca         ###   ########.fr       */
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
	(*i)++;
	while (str[*i] != '\0' && str[*i] != '$' && str[*i] != ' ' \
						&& str[*i] != '\'' && str[*i] != '\"')
	{
		//(*i)++;
		printf("get_in_env:    (*i) = %d\n", (*i));
		printf("get_in_env: str[*i] = %c\n", str[*i]);
		if (!is_key(str[*i]))
			break ;
		(*i)++;
	}
	if (*i == nb_dollar + 1)
		return (str);
	key = ft_substr(str, nb_dollar + 1, *i - nb_dollar - 1);
	printf("get_in_env: key = %s\n", key);
	j = -1;
	while (env[++j]) //нужно будет добавить поиск по своему env и свой критерий остановки
	{
		printf("get_in_env: j = %d\n", j);
		if (strstr(env[j], key)) //нет в библиотеке ft_ 
		{
			tmp = ft_substr(env[j], 0, ln_env(env[j]));
			printf("get_in_env: tmp = %s\n", tmp);
			if (strcmp(key, tmp) == 0) //нет в библиотеке ft_ 
			{
				tmp = ft_substr(env[j], ln_env(env[j]) + 1, ft_strlen(env[j]) - ln_env(env[j]));
				printf("get_in_env: tmp = %s\n", tmp);
				return (tmp);
			}
		}
	}
	tmp = strdup("");
	printf("get_in_env: tmp = %s\n", tmp);
	return (tmp);
}
