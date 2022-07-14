/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:50:42 by stapioca          #+#    #+#             */
/*   Updated: 2022/07/14 21:24:48 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_histori(char *str)
{
	int	fd;
	int	ln;

	fd = open("histori", O_RDWR);
	if (fd == 0)
		exit(-1);
	ln = ft_strlen(str);
	write(fd, str, ln);
	close(fd);
}

char	*ft_readline(char *p)
{
	char	*str;

	str = readline(p);
	if (str)
		add_histori(str);
	return (str);
}
