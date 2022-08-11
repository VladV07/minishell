/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:37:47 by stapioca          #+#    #+#             */
/*   Updated: 2022/08/11 21:28:38 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parser(char *str, char **env)
{
	char	**str_pars_tmp;
	int		i;
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
	printf("parser: str_pars_tmp = %s\n", str_pars_tmp[0]);
	printf("parser: str_pars_tmp = %s\n", str_pars_tmp[1]);
	printf("parser: str_pars_tmp = %s\n", str_pars_tmp[2]);
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
		str_pars_tmp[i] = ft_strtrim(str_pars_tmp[i], " "); // добавить невидемые символы и хз нужна ли вообще
		printf("parser: str_pars_tmp[i] = %s\n", str_pars_tmp[i]);
		g_sh.res_pars[i] = ft_split(str_pars_tmp[i], ' ');
		i++;
	}
	g_sh.res_pars[i] = NULL;
	free(str_pars_tmp);
	printf("parser: g_sh.res_pars[0][0] = %s\n", g_sh.res_pars[0][0]);
	printf("parser: g_sh.res_pars[0][1] = %s\n", g_sh.res_pars[0][1]);
	printf("parser: g_sh.res_pars[0][2] = %s\n", g_sh.res_pars[0][2]);
	printf("parser: g_sh.res_pars[1][0] = %s\n", g_sh.res_pars[1][0]);
	printf("parser: g_sh.res_pars[1][1] = %s\n", g_sh.res_pars[1][1]);
	printf("parser: g_sh.res_pars[1][2] = %s\n", g_sh.res_pars[1][2]);
	printf("parser: g_sh.res_pars[2][0] = %s\n", g_sh.res_pars[2][0]);
	printf("parser: g_sh.res_pars[2][1] = %s\n", g_sh.res_pars[2][1]);
	printf("parser: g_sh.res_pars[2][2] = %s\n", g_sh.res_pars[2][2]);
}
