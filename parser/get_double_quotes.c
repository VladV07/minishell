/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:35:55 by stapioca          #+#    #+#             */
/*   Updated: 2022/10/08 17:06:23 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*go_on_str(char *str, int *i, char **env)
{
	while (str[*i] != '\0')
	{
		(*i)++;
		if (str[*i] == ' ')
			str[*i] = '\t';
		if (str[*i] == '|')
			str[*i] = '\v';
		if (str[*i] == '$')
			str = get_dollar(str, i, env);
		if (str[*i] == '\"')
			break ;
	}
	return (str);
}

char	*get_double_quotes(char *str, int *i, char **env)
{
	int		double_quote;
	char	*str_tmp1;
	char	*str_tmp2;
	char	*str_tmp3;

	double_quote = *i;
	str_tmp1 = ft_substr(str, 0, double_quote);
	str = go_on_str(str, i, env);
	str_tmp2 = ft_substr(str, double_quote + 1, *i - double_quote - 1);
	str_tmp3 = ft_strdup(str + *i + 1);
	str_tmp1 = ft_strjoin(str_tmp1, str_tmp2);
	str_tmp1 = ft_strjoin(str_tmp1, str_tmp3);
	free(str_tmp2);
	free(str_tmp3);
	(*i) = (*i) - 2;
	return (str_tmp1);
}
