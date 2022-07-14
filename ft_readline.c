/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:50:42 by stapioca          #+#    #+#             */
/*   Updated: 2022/07/14 20:54:32 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_histori(char *str)
{
	
}

char	*ft_readline(char *p)
{
	char	*str;

	str = readline(p);
	if (str)
		add_histori(str);
	return (str);
}
