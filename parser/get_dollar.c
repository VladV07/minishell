/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dollar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:29:43 by stapioca          #+#    #+#             */
/*   Updated: 2022/10/08 17:06:43 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_dollar(char *str, int *i, char **env)
{
	int		cop_i;
	int		cop_i2;
	char	*key_znach;
	char	*str_tmp1;
	char	*str_tmp2;

	cop_i = *i;
	cop_i2 = *i;
	key_znach = get_in_env(str, &cop_i, env);
	str_tmp1 = ft_substr(str, 0, *i);
	str_tmp1 = ft_strjoin(str_tmp1, key_znach);
	while (str[*i] != '\0' || str[*i] != '$')
	{
		(*i)++;
		if (!is_key(str[*i]))
			break ;
	}
	str_tmp2 = ft_strdup(str + *i);
	str_tmp1 = ft_strjoin(str_tmp1, str_tmp2);
	*i = cop_i2 + ft_strlen(key_znach) - 1;
	free(key_znach);
	free(str_tmp2);
	return (str_tmp1);
}
