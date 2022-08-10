/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:11:13 by njohanne          #+#    #+#             */
/*   Updated: 2022/08/10 20:47:44 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lexer(char *str)
{
	int		i;
	int		field;
	int		exp_field;
	char	*new_str;
	char	*c;

	field = 0;
	exp_field = 0;
	i = -1;
	new_str = (char *)malloc(sizeof(char));
	c = (char *)malloc(sizeof(char) * 2);
	new_str[0] = '\0';
	c[1] = '\0';
	while (str[++i])
	{
		if (str[i] == 34)
			field++;
		else if (str[i] == 39)
			exp_field++;
		if (str[i] == ' ' && (str[i + 1] == ' ') && ((field % 2) == 0) \
							&& ((exp_field % 2) == 0))
			;
		else if ((str[i] >= 9) && (str[i] <= 13))
			;
		else
		{
			c[0] = str[i];
			new_str = ft_strjoin_free(new_str, c);
		}
	}
	free(c);
	g_sh.str = new_str;
	return (0);
}
