/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:35:55 by stapioca          #+#    #+#             */
/*   Updated: 2022/08/11 21:29:23 by stapioca         ###   ########.fr       */
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
	//printf("get_double_quotes: double_quote = %d\n", double_quote);
	while (str[*i] != '\0')
	{
		(*i)++;
		//printf("get_double_quotes: (*i) = %d\n", (*i));
		/*if (str[*i] == '\\' && (str[*i + 1] == '$' || \
				str[*i + 1] == '\"' || str[*i + 1] == '\\'))
			str = get_slesh(str, i);*/
		if (str[*i] == '$')
			get_dollar(str, i, env);
		if (str[*i] == '\"')
			break ;
	}
	str_tmp1 = ft_substr(str, 0, double_quote);
	//printf("get_double_quotes: str_tmp1 = %s\n", str_tmp1);
	str_tmp2 = ft_substr(str, double_quote + 1, *i - double_quote - 1);
	//printf("get_double_quotes: str_tmp2 = %s\n", str_tmp2);
	str_tmp3 = ft_strdup(str + *i + 1);
	//printf("get_double_quotes: str_tmp1 = %s\n", str_tmp3);
	str_tmp1 = ft_strjoin(str_tmp1, str_tmp2);
	//printf("get_double_quotes: str_tmp1 = %s\n", str_tmp1);
	str_tmp1 = ft_strjoin(str_tmp1, str_tmp3);
	printf("get_double_quotes: str_tmp1 = %s\n", str_tmp1);
	free(str_tmp2);
	free(str_tmp3);
	//free(str);
	(*i) = (*i) - 2;
	//printf("get_double_quotes: (*i)end = %d\n", (*i));
	return (str_tmp1);
}
