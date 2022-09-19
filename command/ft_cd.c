/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:58:50 by njohanne          #+#    #+#             */
/*   Updated: 2022/09/19 04:59:27 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_go_home(void)
{
	char	*c;
	char	**ndir;
	char	dir[1024];

	getcwd(dir, 1024);
	c = ft_get_env("HOME");
	if (c == NULL)
		return (1);			//директория не найдена
	ndir = ft_split(c, '=');
	chdir(ndir[1]);
	ft_free_env(ndir);
	ft_set_env(&dir[0], "OLDPWD");
	getcwd(dir, 1024);
	ft_set_env(&dir[0], "PWD");	
	return (0);
}

int	ft_cd(char **str)
{
	char	c[1024];

	getcwd(c, 1024);
	if (str[1] == NULL)
		return (ft_go_home());
	if (chdir(str[1]) < 0)
		return (1);
	ft_set_env(&c[0], "OLDPWD");
	getcwd(c, 1024);
	ft_set_env(&c[0], "PWD");
	return (0);
}
