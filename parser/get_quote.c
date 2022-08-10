/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:32:53 by stapioca          #+#    #+#             */
/*   Updated: 2022/08/10 18:46:08 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_quote(char *str, int *i)
{
	int		nb_quote;
	char	*str_tmp1;
	char	*str_tmp2;
	char	*str_tmp3;

	nb_quote = *i;
	while (str[*i] != '\0')
	{
		(*i)++;
		if (str[*i] == '\'')
			break ;
	}
	str_tmp1 = ft_substr(str, 0, nb_quote);
	str_tmp2 = ft_substr(str, nb_quote + 1, *i - nb_quote - 1);
	str_tmp3 = ft_strdup(str + *i + 1);
	str_tmp1 = ft_strjoin(str_tmp1, str_tmp2);
	str_tmp1 = ft_strjoin(str_tmp1, str_tmp3);
	free(str_tmp2);
	free(str_tmp3);
	free(str);
	return (str_tmp1);
}
