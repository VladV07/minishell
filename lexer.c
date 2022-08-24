/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:11:13 by njohanne          #+#    #+#             */
/*   Updated: 2022/08/24 19:25:40 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check(char *str)
{
	int	len;
	int i;

	i = -1;
	str = ft_strtrim(str, " ");
	len = ft_strlen(str);
	if (str[len - 1] == '&' || str[len - 1] == '|'
		||str[len - 1] == '>' || str[len - 1] == '<')
		return (1);
	while (str[++i])
	{
		if (str[i] == '&' && str[i + 1] == '&')
			return (1);
		if (str[i] == '|' && str[i + 1] == '|')
			return (1);
	}
	return (0);
}

int	lexer(char *str)
{
	int		i;
	int		field;
	int		exp_field;
	char	*new_str;
	char	*c;

	if (ft_check(str))
		return (1);
	field = 0;
	exp_field = 0;
	i = -1;
	new_str = (char *)malloc(sizeof(char));
	c = (char *)malloc(sizeof(char) * 2);
	new_str[0] = '\0';
	c[1] = '\0';
	while (str[++i])
	{
		if (str[i] == '\"' && !(exp_field % 2))
			field++;
		else if (str[i] == '\'' && !(field % 2))
			exp_field++;
		if ((str[i] == ' ' && (str[i + 1] == ' ') && ((field % 2) == 0) \
	 			&& ((exp_field % 2) == 0)) || ((str[i] >= 9) && (str[i] <= 13)))
	 		;
		else if ((str[i] == '>' && str[i + 1] == '>') || (str[i] == '<' && str[i + 1] == '<'))
		{
			c[0] = str[i++];
 			new_str = ft_strjoin_free(new_str, c);
			new_str = ft_strjoin_free(new_str, c);
		}		
		else if ((str[i] != ' ' && str[i]) && (str[i + 1] == '>' || str[i + 1] == '<' || str[i + 1] == '&' || str[i + 1] == '|'))
		{
 			c[0] = str[i];
 			new_str = ft_strjoin_free(new_str, c);
			if (str[i + 1] != '>' || str[i + 1] != '<')
			{
				c[0] = ' ';
 				new_str = ft_strjoin_free(new_str, c);
			}
		}
		else
		{
 			c[0] = str[i];
 			new_str = ft_strjoin_free(new_str, c);
					
		}
		if (str[i + 1] != ' ' && (str[i] == '|' || str[i] == '&' || str[i] == '<' || str[i] == '>'))
		{
			c[0] = ' ';
			new_str = ft_strjoin_free(new_str, c);				
		}		
	}


	
	// while (str[++i])
	// {
	// 	if (str[i] == 34)
	// 		field++;
	// 	else if (str[i] == 39)
	// 		exp_field++;
	// 	if ((str[i] == '&' || str[i] == '|') && (str[i + 1] == '&' || str[i + 1] == '|'))
	// 			return (1);
	// 	if ((str[i] == ' ' && (str[i + 1] == ' ') && ((field % 2) == 0) \
	// 			&& ((exp_field % 2) == 0)) || ((str[i] >= 9) && (str[i] <= 13)))
	// 		;
	// 	else if ((str[i] == '>' || str[i] == '<' || str[i] == '&' \
	// 			|| str[i] == '|') && str[i + 1] != ' ')
	// 	{
	// 		if ((str[i] == '>' && str[i + 1] == '>') \
	// 			|| (str[i + 1] == '<' && str[i + 1] == '<'))
	// 		{
	// 			c[0] = str[i];
	// 			new_str = ft_strjoin_free(new_str, c);
	// 			c[0] = str[++i];
	// 			new_str = ft_strjoin_free(new_str, c);
	// 		}
	// 		else
	// 		{
	// 			c[0] = ' ';
	// 			new_str = ft_strjoin_free(new_str, c);
	// 			c[0] = str[i];
	// 			new_str = ft_strjoin_free(new_str, c);
				
	// 		}
	// 	}
	// 	else
	// 	{
	// 		c[0] = str[i];
	// 		new_str = ft_strjoin_free(new_str, c);
	// 	}
	//}
	free(c);
	free(g_sh.str);
	if ((exp_field % 2) || (field % 2))
	{
		free(new_str);
		return (1);
	}
	g_sh.str = new_str;
	return (0);
}
