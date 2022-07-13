/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:46:55 by stapioca          #+#    #+#             */
/*   Updated: 2022/07/13 20:26:07 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstclear(t_list **mass)
{
	if (!mass || !*mass)
		return ;
	ft_lstclear(&(*mass)->next);
	free (*mass);
	*mass = NULL;
}
