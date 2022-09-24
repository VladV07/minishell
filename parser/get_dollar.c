/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dollar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:29:43 by stapioca          #+#    #+#             */
/*   Updated: 2022/09/24 18:02:40 by stapioca         ###   ########.fr       */
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
	printf("get_dollar: key_znach = %s\n", key_znach);
	str_tmp1 = ft_substr(str, 0, *i);
	printf("get_dollar: str_tmp1 = %s\n", str_tmp1);
	str_tmp1 = ft_strjoin(str_tmp1, key_znach);
	printf("get_dollar: str_tmp1 = %s\n", str_tmp1);
	printf("get_dollar: (*i) = %d\n", (*i));
	while (str[*i] != '\0' || str[*i] != '$')
	{
		(*i)++;
		printf("get_dollar: (*i) = %d\n", (*i));
		if (!is_key(str[*i]))
			break ;
	}
	printf("get_dollar: (*i) = %d\n", (*i));
	printf("get_dollar: *(str + *i) = %c\n", *(str + *i));
	printf("get_dollar: *(str + *i + 1) = %c\n", *(str + *i + 1));
	str_tmp2 = ft_strdup(str + *i);
	printf("get_dollar: str_tmp2 = %s\n", str_tmp2);
	str_tmp1 = ft_strjoin(str_tmp1, str_tmp2);
	printf("get_dollar: str_tmp1 = %s\n", str_tmp1);
	*i = cop_i2 + ft_strlen(key_znach) - 1;
	printf("get_dollar:         [*i] = %d\n", (*i));
	printf("get_dollar: str_tmp1[*i] = %c\n", str_tmp1[*i]);
	free(key_znach);
	free(str_tmp2);
	//free(str);
	return (str_tmp1);
}
