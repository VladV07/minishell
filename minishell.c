/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:06:00 by stapioca          #+#    #+#             */
/*   Updated: 2022/08/11 21:24:34 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>  // потом убрать

void	init_shell(void)
{
	g_sh.stop_flag = 0;
	g_sh.res_pars = NULL;
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
	g_sh.str = strdup(" 1 2 3| 				4    55555 6|7 \'\"8\'\"6\"8\'8\'8\"9\"      dfgghfg      ");
	//g_sh.str = ft_strdup("\"a\"	b\"	c\"	d\"\"\" 	 \'	   \'  b");
	//g_sh.str = ft_strdup("\"a\"	b\"	c\"	d\"\"\" 	 \'	   \'  b");
	init_shell();
	while (!g_sh.stop_flag)
	{
		ch_err = lexer(g_sh.str);
		if (!ch_err)
		{
			printf("g_sh.str= %s\n", g_sh.str);
			parser(g_sh.str, env);
			g_sh.stop_flag = 1;
		}
		else
			printf("command error\n");
	}
	return (0);
}
