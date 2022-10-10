/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:06:00 by stapioca          #+#    #+#             */
/*   Updated: 2022/10/10 23:19:51 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	g_sh;

int	ft_len_env(char **genv)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (genv[++i])
		len++;
	return (len);
}

char	**ft_cpy_env(char **nenv, char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		nenv[i] = (char *)malloc(sizeof(char *) * strlen(env[i]));
		nenv[i] = memcpy(nenv[i], env[i], strlen(env[i]));
	}
	return (nenv);
}

void	ft_get_in_env(char **env)
{
	int	len;

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
	init_shell(env);
	// signal(SIGINT, ctrl_c);
	// signal(SIGQUIT, SIG_IGN);
	while (!g_sh.stop_flag)
	{
		g_sh.str = readline("minishell $");
		if (g_sh.str)
			add_history(g_sh.str);
		ch_err = lexer(g_sh.str);
		if (!ch_err)
		{
			parser(g_sh.str, g_sh.env);
			executor(g_sh.res_pars);
			free_g_sh();
		}
		else
			printf("command error\n");
	}
	free_and_exit(0);
	return (0);
}
