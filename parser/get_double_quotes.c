/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:35:55 by stapioca          #+#    #+#             */
/*   Updated: 2022/08/10 21:04:19 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_double_quotes(char *str, int *i, char **env)
{
	int		double_quote;
	char	*str_tmp1;
	char	*str_tmp2;
	char	*str_tmp3;

	double_quote = *i;
	while (str[*i] != '\0')
	{
		(*i)++;
		if (str[*i] == '\\' && (str[*i + 1] == '$' || \
				str[*i + 1] == '\"' || str[*i + 1] == '\\'))
			str = get_slesh(str, i);
		if (str[*i] == '$')
			get_dollar(str, i, env);
		if (str[*i] == '\"')
			break ;
	}
	str_tmp1 = ft_substr(str, 0, double_quote);
	str_tmp2 = ft_substr(str, double_quote + 1, *i - double_quote - 1);
	str_tmp3 = ft_strdup(str + *i + 1);
	str_tmp1 = ft_strjoin(str_tmp1, str_tmp2);
	str_tmp1 = ft_strjoin(str_tmp1, str_tmp3);
	printf("get_double_quotes: str_tmp1 = %s\n", str_tmp1);
	free(str_tmp2);
	free(str_tmp3);
	free(str);
	return (str_tmp1);
}
