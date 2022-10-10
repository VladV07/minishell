/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:37:47 by stapioca          #+#    #+#             */
/*   Updated: 2022/10/08 16:52:35 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_arr_g_sh_res_pars(void)
{
	int	i;
	int	j;

	i = 0;
	while (g_sh.res_pars[i] != NULL)
	{
		j = 0;
		while (g_sh.res_pars[i][j] != NULL)
		{
			printf("g_sh.res_pars[%d][%d]=%s\n", i, j, g_sh.res_pars[i][j]);
			j++;
		}
		i++;
	}
}

void	kostyl_return(void)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (g_sh.res_pars[i])
	{
		j = 0;
		while (g_sh.res_pars[i][j])
		{
			k = 0;
			while (g_sh.res_pars[i][j][k])
			{
				if (g_sh.res_pars[i][j][k] == '\t')
					g_sh.res_pars[i][j][k] = ' ';
				if (g_sh.res_pars[i][j][k] == '\v')
					g_sh.res_pars[i][j][k] = '|';
				k++;
			}
			j++;
		}
		i++;
	}
}

char	*go_on_str_parser(char *str, char **env)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			str = get_quote(str, &i);
		if (str[i] == '\\')
			str = get_slesh(str, &i);
		if (str[i] == '\"')
			str = get_double_quotes(str, &i, env);
		if (str[i] == '$')
			str = get_dollar(str, &i, env);
		i++;
	}
	return (str);
}

void	parser(char *str, char **env)
{
	char	**str_pars_tmp;
	int		i;

	str = go_on_str_parser(str, env);
	str_pars_tmp = ft_split(str, '|');
	i = 0;
	while (str_pars_tmp[i])
		i++;
	g_sh.res_pars = (char ***)malloc(sizeof(char **) * \
								(i + 1));
	i = -1;
	while (str_pars_tmp[++i])
		g_sh.res_pars[i] = ft_split(str_pars_tmp[i], ' ');
	g_sh.res_pars[i] = NULL;
	kostyl_return();
	i = 0;
	while (str_pars_tmp[i])
		free(str_pars_tmp[i++]);
	free(str_pars_tmp);
}
