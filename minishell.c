/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:06:00 by stapioca          #+#    #+#             */
/*   Updated: 2022/09/12 14:57:15 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_len_env(char **env)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while(env[++i])
		len++;
	return(len);
}

char	**ft_cpy_env(char **nenv, char **env)
{
	int	i;
	int	j;

	i = -1;
	while (env[++i])
	{
		j = -1;
		while (env[i][++j])
		{
			nenv[i] = (char *)malloc(sizeof(char *) * strlen(env[i]));
			nenv[i] = memcpy(nenv[i], env[i], strlen(env[i]));
		}
	}
	return(nenv);
}

void	ft_get_in_env(char **env)
{
	int len;

	len = ft_len_env(env);
	g_sh.env = (char **)malloc(sizeof(char **) * len + 1);
	g_sh.env[len] = NULL;
	g_sh.env = ft_cpy_env(g_sh.env, env);
}

void	init_shell(char **env)
{
	g_sh.stop_flag = 0;
	g_sh.plase_redirect = 0;
	g_sh.res_pars = NULL;
	g_sh.commands = (char **)malloc(sizeof(char *) * 9);
	g_sh.commands[0] = ft_strdup("echo");
	g_sh.commands[1] = ft_strdup("cd");
	g_sh.commands[2] = ft_strdup("pwd");
	g_sh.commands[3] = ft_strdup("export");
	g_sh.commands[4] = ft_strdup("unset");
	g_sh.commands[5] = ft_strdup("env");
	g_sh.commands[6] = ft_strdup("exit");
	g_sh.commands[7] = NULL;
	ft_get_in_env(env);
}

/* тут последовательно перебираем '' \ "" $ ; | > >> < ' '  */
/* get_in_env.c убрать #include <string.h> */

int	main(int argc, char **argv, char **env)
{
	int	ch_err;

	(void)argc;
	(void)argv;
	//g_sh.str = strdup("co$USER mman\\nn\'dd000\\\'00co\"mm\\\"\"an\"\'dddd\'a");
	//g_sh.str = strdup("\"8\"8\"8\"");
	//g_sh.str = strdup(" 1 2 3| 				4    55555 6|7 \"8\"8\"8 \" 9");
	//g_sh.str = strdup(" 1 2 3| 				4    55555 6|7 \'\"8\'\"6\"8\'8\'8\"9\"      dfgghfg      ");
	//g_sh.str = ft_strdup("\"a\"	b\"	c\"	d\"\"\" 	 \'	   \'  b");
	//g_sh.str = ft_strdup("\"a\"	b\"	c\"	d\"\"\" 	 \'	   \'  b");
	//g_sh.str = ft_strdup ("text");
	init_shell(env);
	while (!g_sh.stop_flag)
	{
		g_sh.str = readline("minishell $");
		ch_err = lexer(g_sh.str);
		if (!ch_err)
		{
			printf("g_sh.str= %s\n", g_sh.str);
			parser(g_sh.str, env);
			executor(g_sh.res_pars, env);
			//g_sh.stop_flag = 1;
		}
		else
			printf("command error\n");
		printf("g_sh.str = %s\n", g_sh.str); //
		free_g_sh();
		//system("leaks executablename");
	}
	free_and_exit(0);
	return (0);
}
