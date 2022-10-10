/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_herdog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:17:33 by vlad              #+#    #+#             */
/*   Updated: 2022/10/10 22:24:50 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	do_herdog(char *res_pars)
{
	char	*str;
	char	*str_new;
	int		rd_in;

	g_sh.fd_stdin = open("heredog", O_WRONLY | O_CREAT | O_TRUNC, 0664);
	while (1)
	{
		str = readline("heredog>");
		if (ft_strcmp(str, res_pars) == 0)
		{
			close(g_sh.fd_stdin);
			g_sh.fd_stdin = open("heredog", O_RDONLY, 0664);
			break ;
		}
		str_new = ft_strjoin(str, "\n");
		free(str);
		write(g_sh.fd_stdin, str_new, ft_strlen(str_new));
	}
	rd_in = 1;
	return (rd_in);
}
