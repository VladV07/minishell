/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:15:58 by vlad              #+#    #+#             */
/*   Updated: 2022/10/10 22:24:52 by vlad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	do_rd_out_one(char *res_pars, int *rd_out)
{
	g_sh.fd_stdout = open(res_pars, \
		O_WRONLY | O_CREAT | O_TRUNC, 0664);
	*rd_out = 1;
}

void	do_rd_out_two(char *res_pars, int *rd_out)
{
	g_sh.fd_stdout = open(res_pars, \
		O_WRONLY | O_CREAT | O_APPEND, 0664);
	*rd_out = 1;
}

void	do_rd_in_one(char *res_pars, int *rd_in)
{
	g_sh.fd_stdin = open(res_pars, O_RDONLY, 0664);
	*rd_in = 1;
}

int	go_on_res_pars(char **res_pars, int *rd_in, int *rd_out, int j)
{
	int	i;

	i = 0;
	while (res_pars[i])
	{
		if (ft_strcmp(res_pars[i], ">") == 0)
			do_rd_out_one(res_pars[++i], rd_out);
		else if (ft_strcmp(res_pars[i], ">>") == 0)
			do_rd_out_two(res_pars[++i], rd_out);
		else if (ft_strcmp(res_pars[i], "<") == 0)
			do_rd_in_one(res_pars[++i], rd_in);
		else if (ft_strcmp(res_pars[i], "<<") == 0)
		{
			i++;
			*rd_in = do_herdog(res_pars[i]);
		}
		else
		{
			g_sh.cmd_and_args[j] = res_pars[i];
			j++;
		}
		i++;
	}
	return (j);
}

int	do_redirections(char **res_pars)
{
	int	i;
	int	j;
	int	rd_in;
	int	rd_out;

	i = 0;
	while (res_pars[i])
		i++;
	g_sh.cmd_and_args = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	j = 0;
	rd_in = 0;
	rd_out = 0;
	j = go_on_res_pars(res_pars, &rd_in, &rd_out, j);
	g_sh.cmd_and_args[j] = NULL;
	if (rd_in == 1 && rd_out == 1)
		return (3);
	if (rd_in == 1 && rd_out == 0)
		return (2);
	if (rd_in == 0 && rd_out == 1)
		return (1);
	return (0);
}
