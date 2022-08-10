/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:06:00 by stapioca          #+#    #+#             */
/*   Updated: 2022/08/10 20:58:57 by stapioca         ###   ########.fr       */
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
	(void)argc;
	(void)argv;
	(void)env;
	//g_sh.str = strdup("co$USER mma'n\\nn\'dd000\\\'00co\"mm\\\"\"an\'dddd\'a");
	g_sh.str = strdup("\"8\"8\"8\"");
	//g_sh.str = strdup(" 1 2 3| 				4    55555 6|7 \"8\"8\"8 \" 9");
	//g_sh.str = ft_strdup("\"a\"	b\"	c\"	d\"\"\" 	 \'	   \'  b");
	//g_sh.str = ft_strdup("\"a\"	b\"	c\"	d\"\"\" 	 \'	   \'  b");
	init_shell();
	while (!g_sh.stop_flag)
	{
		lexer(g_sh.str);
		//lector(g_sh.str);
		printf("g_sh.str= %s\n", g_sh.str);
		parser(g_sh.str, env);
		g_sh.stop_flag = 1;
	}
	return (0);
}
