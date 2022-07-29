/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:06:00 by stapioca          #+#    #+#             */
/*   Updated: 2022/07/29 21:46:21 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>

t_data	g_sh;

void	init_shell(void)
{
	g_sh.stop_flag = 0;
}

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

void	parser(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			get_quote(str, &i);
		i++;
	}
}

int	main(void)
{
	char	*str;

	str = strdup("1com'2man'3dddd");
	init_shell();
	while (!g_sh.stop_flag)
	{
		init_shell();
		parser(str);
	}
	return (0);
}
