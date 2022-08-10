/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:06:00 by stapioca          #+#    #+#             */
/*   Updated: 2022/08/10 19:18:55 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>  // потом убрать

t_data	g_sh;

void	init_shell(void)
{
	g_sh.stop_flag = 0;
	g_sh.res_pars = NULL;
}

int	is_key(char ch)
{
	if (ch == '_' || ft_isalnum(ch))
	{
		return (1);
	}
	return (0);
}

int	ln_env(char *env_j)
{
	int	i;

	i = 0;
	while (env_j[i] != '=' && env_j[i] != '\0')
		i++;
	return (i);
}

char	*get_in_env(char *str, int *i, char **env)
{
	int		nb_dollar;
	int		j;
	char	*key;
	char	*tmp;

	nb_dollar = *i;
	while (str[*i] != '\0')
	{
		(*i)++;
		if (!is_key(str[*i]))
			break ;
	}
	if (*i == nb_dollar + 1)
		return (str);
	key = ft_substr(str, nb_dollar + 1, *i - nb_dollar - 1);
	j = -1;
	while (env[++j])
	{
		if (strstr(env[j], key)) //нет в библиотеке ft_ 
		{
			tmp = ft_substr(env[j], 0, ln_env(env[j]));
			if (strcmp(key, tmp) == 0) //нет в библиотеке ft_ 
				break ;
		}
	}
	tmp = ft_substr(env[j], ln_env(env[j]) + 1, ft_strlen(env[j]) - ln_env(env[j]));
	printf("tmp = %s\n", tmp);
	return (tmp);
}

char	*get_dollar(char *str, int *i, char **env)
{
	int		cop_i;
	char	*key_znach;
	char	*str_tmp1;
	char	*str_tmp2;

	cop_i = *i;
	key_znach = get_in_env(str, &cop_i, env);
	str_tmp1 = ft_substr(str, 0, *i);
	str_tmp1 = ft_strjoin(str_tmp1, key_znach);
	while (str[*i] != '\0')
	{
		(*i)++;
		if (!is_key(str[*i]))
			break ;
	}
	str_tmp2 = ft_strdup(str + *i + 1);
	str_tmp1 = ft_strjoin(str_tmp1, str_tmp2);
	free(key_znach);
	free(str_tmp2);
	free(str);
	return (str_tmp1);
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
	printf("str_tmp1 = %s\n", str_tmp1);
	return (str_tmp1);
}

char	*get_slesh(char *str, int *i)
{
	int		nb_slesh;
	char	*str_tmp1;
	char	*str_tmp2;

	nb_slesh = *i;
	str_tmp1 = ft_substr(str, 0, nb_slesh);
	str_tmp2 = ft_strdup(str + nb_slesh + 1);
	str_tmp1 = ft_strjoin(str_tmp1, str_tmp2);
	free(str_tmp2);
	free(str);
	(*i)++;
	printf("str_tmp1 = %s\n", str_tmp1);
	return (str_tmp1);
}

char	*get_double_quotes(char *str, int *i, char **env)
{
	int		double_quote;
	char	*str_tmp1;
	char	*str_tmp2;
	char	*str_tmp3;

	double_quote = *i;
	while (str[*i] != '\0')
	{
		(*i)++;
		if (str[*i] == '\\' && (str[*i + 1] == '$' || \
				str[*i + 1] == '\"' || str[*i + 1] == '\\'))
			str = get_slesh(str, i);
		if (str[*i] == '$')
			get_dollar(str, i, env);
		if (str[*i] == '\"')
			break ;
	}
	str_tmp1 = ft_substr(str, 0, double_quote);
	str_tmp2 = ft_substr(str, double_quote + 1, *i - double_quote - 1);
	str_tmp3 = ft_strdup(str + *i + 1);
	str_tmp1 = ft_strjoin(str_tmp1, str_tmp2);
	str_tmp1 = ft_strjoin(str_tmp1, str_tmp3);
	free(str_tmp2);
	free(str_tmp3);
	free(str);
	printf("str_tmp1 = %s\n", str_tmp1);
	return (str_tmp1);
}

void	parser(char *str, char **env)
{
	/* тут последовательно перебираем '' \ "" $ ; | > >> < ' '*/
	char	**str_pars_tmp;
	int		i;
	int		size_str_pars_tmp;

	i = 0;
	printf("str = %s\n", str);
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
	printf("str = %s\n", str);
	str_pars_tmp = ft_split(str, '|');
	printf("str_pars_tmp = %s\n", str_pars_tmp[0]);
	printf("str_pars_tmp = %s\n", str_pars_tmp[1]);
	printf("str_pars_tmp = %s\n", str_pars_tmp[2]);
	i = -1;
	size_str_pars_tmp = 0;
	while (str_pars_tmp[++i])
		size_str_pars_tmp = size_str_pars_tmp + ft_strlen(str_pars_tmp[i]);
	printf("size_str_pars_tmp = %d\n", size_str_pars_tmp);
	i = 0;
	g_sh.res_pars = (char ***)malloc(sizeof(char ***) * (size_str_pars_tmp + 1)); // нужно правильно посчитать и выделить память
	//if (!g_sh.res_pars)
	//	exit_err();
	while (str_pars_tmp[i])
	{
		str_pars_tmp[i] = ft_strtrim(str_pars_tmp[i], " "); // добавить невидемые символы и хз нужна ли вообще
		g_sh.res_pars[i] = ft_split(str_pars_tmp[i], ' ');
		i++;
	}
	g_sh.res_pars[i] = NULL;
	free(str_pars_tmp);
	printf("g_sh.res_pars = %s\n", g_sh.res_pars[0][0]);
	printf("g_sh.res_pars = %s\n", g_sh.res_pars[1][0]);
	printf("g_sh.res_pars = %s\n", g_sh.res_pars[2][0]);
	printf("g_sh.res_pars = %s\n", g_sh.res_pars[0][1]);
	printf("g_sh.res_pars = %s\n", g_sh.res_pars[1][1]);
	printf("g_sh.res_pars = %s\n", g_sh.res_pars[2][1]);
	printf("g_sh.res_pars = %s\n", g_sh.res_pars[0][2]);
	printf("g_sh.res_pars = %s\n", g_sh.res_pars[1][2]);
	printf("g_sh.res_pars = %s\n", g_sh.res_pars[2][2]);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	//g_sh.str = strdup("co$USER mma'n\\nn\'dd000\\\'00co\"mm\\\"\"an\'dddd\'a");
	g_sh.str = strdup(" 1 2 3| 4 55555 6 |7 888 9");
	init_shell();
	while (!g_sh.stop_flag)
	{
		g_sh.str = lexer(g_sh.str);
		//lector(g_sh.str);
		parser(g_sh.str, env);
		g_sh.stop_flag = 1;
	}
	return (0);
}
