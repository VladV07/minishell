/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:37:47 by stapioca          #+#    #+#             */
/*   Updated: 2022/09/12 21:52:55 by stapioca         ###   ########.fr       */
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
				k++;
			}
			j++;
		}
		i++;
	}
}

void	parser(char *str, char **env)
{
	char	**str_pars_tmp;
	int		i;
	//int		size_str_pars_tmp;

	printf("parser: str = %s\n", str);
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
		//printf("parser: i = %d\n", i);
	}
	printf("parser: str = %s\n", str);
	str_pars_tmp = ft_split(str, '|');
	printf("parser: str_pars_tmp[0] = %s\n", str_pars_tmp[0]);
	//i = -1;
	//size_str_pars_tmp = 0;
	//while (str_pars_tmp[++i])
	//	size_str_pars_tmp = size_str_pars_tmp + ft_strlen(str_pars_tmp[i]);
	//printf("parser: size_str_pars_tmp = %d\n", size_str_pars_tmp);

	i = 0;
	while (str_pars_tmp[i])
		i++;
	g_sh.res_pars = (char ***)malloc(sizeof(char **) * \
								(i + 1));
								
	//if (!g_sh.res_pars)
	//	exit_err();
	i = 0;
	while (str_pars_tmp[i])
	{
		printf("parser: str_pars_tmp[%d] = %s\n", i, str_pars_tmp[i]);
		g_sh.res_pars[i] = ft_split(str_pars_tmp[i], ' ');
		i++;
	}
	g_sh.res_pars[i] = NULL;
	kostyl_return();
	i = 0;
	while (str_pars_tmp[i])
		free(str_pars_tmp[i++]);
	free(str_pars_tmp);
	printf("g_sh.str = %s\n", g_sh.str); //
	printf("str = %s\n", str); //
	//printf("str pars addr= %p\n", &str);
	//free(str);
	print_arr_g_sh_res_pars();
}
