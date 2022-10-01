/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:11:13 by njohanne          #+#    #+#             */
/*   Updated: 2022/10/01 20:54:40 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check(char *str)
{
	int		len;
	int		i;
	char	*str_new;

	i = -1;
	str_new = ft_strtrim(str, " ");
	len = ft_strlen(str_new);
	if (str_new[len - 1] == '&' || str_new[len - 1] == '|'
		||str_new[len - 1] == '>' || str_new[len - 1] == '<')
		return (1);
	while (str_new[++i])
	{
		if (str_new[i] == '&' && str_new[i + 1] == '&')
			return (1);
		if (str_new[i] == '|' && str_new[i + 1] == '|')
			return (1);
	}
	free(str_new);
	return (0);
}

void	ft_field(int *exp_field, int *field, char *c)
{
	if (c[0] == '\"' && !((*exp_field) % 2))
		(*field)++;
	else if (c[0] == '\'' && !((*field) % 2))
		(*exp_field)++;
}

char	*ft_new_str(char *str, int *exp_field, int *field, char *new_str)
{
	int		i;
	char	*c;

	i = -1;
	c = (char *)malloc(sizeof(char) * 2);
	c[1] = '\0';
	while (str[++i])
	{
		c[0] = str[i];
		ft_field(exp_field, field, c);
		if ((str[i] == ' ' && (str[i + 1] == ' ') && ((*field % 2) == 0) \
			&& ((*exp_field % 2) == 0)) || ((str[i] >= 9) && (str[i] <= 13)))
			;
		else if ((str[i] == '>' && str[i + 1] == '>') || (str[i] == '<' \
			&& str[i + 1] == '<'))
		{
			i++;
			new_str = ft_strjoin_free(new_str, c);
			new_str = ft_strjoin_free(new_str, c);
		}		
		else if ((str[i] != ' ' && str[i]) && (str[i + 1] == '>' \
			|| str[i + 1] == '<' || str[i + 1] == '&' || str[i + 1] == '|'))
		{
			new_str = ft_strjoin_free(new_str, c);
			if (str[i + 1] != '>' || str[i + 1] != '<')
				new_str = ft_strjoin_free(new_str, " ");
		}
		else
			new_str = ft_strjoin_free(new_str, c);
		if (str[i + 1] != ' ' && (str[i] == '|' || str[i] == '&' \
			|| str[i] == '<' || str[i] == '>'))
			new_str = ft_strjoin_free(new_str, " ");
	}
	free(c);
	return (new_str);
}

int	lexer(char *str)
{
	int		field;
	int		exp_field;
	char	*new_str;

	if (ft_check(str))
		return (1);
	field = 0;
	exp_field = 0;
	new_str = (char *)malloc(sizeof(char));
	new_str[0] = '\0';
	new_str = ft_new_str(str, &exp_field, &field, new_str);
	free(g_sh.str);
	if ((exp_field % 2 != 0) || (field % 2 != 0))
	{
		free(new_str);
		return (1);
	}
	g_sh.str = new_str;
	return (0);
}
