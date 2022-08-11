/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dollar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:29:43 by stapioca          #+#    #+#             */
/*   Updated: 2022/08/11 20:16:22 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_dollar(char *str, int *i, char **env)
{
	int		cop_i;
	char	*key_znach;
	char	*str_tmp1;
	char	*str_tmp2;

	cop_i = *i;
	key_znach = get_in_env(str, &cop_i, env);
	str_tmp1 = ft_substr(str, 0, *i);
	str_tmp1 = ft_strjoin(str_tmp1, key_znach);
	while (str[*i] != '\0')
	{
		(*i)++;
		if (!is_key(str[*i]))
			break ;
	}
	str_tmp2 = ft_strdup(str + *i + 1);
	str_tmp1 = ft_strjoin(str_tmp1, str_tmp2);
	printf("get_dollar: str_tmp1 = %s\n", str_tmp1);
	free(key_znach);
	free(str_tmp2);
	//free(str);
	return (str_tmp1);
}
