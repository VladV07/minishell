/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:37:47 by stapioca          #+#    #+#             */
/*   Updated: 2022/08/19 21:45:29 by stapioca         ###   ########.fr       */
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

void	parser(char *str, char **env)
{
	char	**str_pars_tmp;
	int		i;
	//int		j;
	int		size_str_pars_tmp;

	i = 0;
	printf("parser: str = %s\n", str);
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
		//printf("parser: i = %d\n", i);
	}
	printf("parser: str = %s\n", str);
	str_pars_tmp = ft_split(str, '|');
	printf("parser: str_pars_tmp[0] = %s\n", str_pars_tmp[0]);
	//printf("parser: str_pars_tmp[1] = %s\n", str_pars_tmp[1]);
	//printf("parser: str_pars_tmp[2] = %s\n", str_pars_tmp[2]);
	//printf("parser: str_pars_tmp[3] = %s\n", str_pars_tmp[3]);
	i = -1;
	size_str_pars_tmp = 0;
	while (str_pars_tmp[++i])
		size_str_pars_tmp = size_str_pars_tmp + ft_strlen(str_pars_tmp[i]);
	printf("parser: size_str_pars_tmp = %d\n", size_str_pars_tmp);
	i = 0;
	g_sh.res_pars = (char ***)malloc(sizeof(char ***) * \
								(size_str_pars_tmp + 1));
	//if (!g_sh.res_pars)
	//	exit_err();
	while (str_pars_tmp[i])
	{
		printf("parser: str_pars_tmp[%d] = %s\n", i, str_pars_tmp[i]);
		g_sh.res_pars[i] = ft_split(str_pars_tmp[i], ' ');
		i++;
	}
	g_sh.res_pars[i] = NULL;
	print_arr_g_sh_res_pars();
	/*
	i = 0;
	while (g_sh.res_pars[i])
	{
		j = 0;
		while (g_sh.res_pars[i][j])
		{
			if (g_sh.res_pars[i][j] == '\'')
				g_sh.res_pars = get_quote(g_sh.res_pars, &j);
			if (g_sh.res_pars[i][j] == '\\')
				g_sh.res_pars = get_slesh(g_sh.res_pars, &j);
			if (g_sh.res_pars[i][j] == '\"')
				g_sh.res_pars = get_double_quotes(g_sh.res_pars, &j, env);
			if (g_sh.res_pars[i][j] == '$')
				g_sh.res_pars = get_dollar(g_sh.res_pars, &j, env);
			j++;
			//printf("parser: i = %d\n", i);
		}
		i++;
	}
	print_arr_g_sh_res_pars();
	*/
	free(str_pars_tmp);
}
