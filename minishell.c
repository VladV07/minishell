/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:06:00 by stapioca          #+#    #+#             */
/*   Updated: 2022/07/13 20:48:28 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

t_data	g_sh;

void	init_shell(void)
{
	g_sh.stop_flag = 0;
}

int	main(void)
{
	init_shell();
	while (!g_sh.stop_flag)
	{
		
	}
	return (0);
}
