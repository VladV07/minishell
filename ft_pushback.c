/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:47:23 by stapioca          #+#    #+#             */
/*   Updated: 2022/07/13 20:26:26 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pushback(t_list **lst, t_list *elem)
{
	t_list	*tmp;

	if (!lst || !elem)
		return ;
	if (!*lst)
	{
		*lst = elem;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = elem;
}
