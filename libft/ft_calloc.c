/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:19:00 by stapioca          #+#    #+#             */
/*   Updated: 2021/10/26 19:30:19 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*tp;
	size_t	i;

	tp = NULL;
	i = 0;
	tp = malloc(count * size);
	if (tp == NULL)
		return (NULL);
	while (i < count * size)
	{
		tp[i] = 0;
		i++;
	}
	return (tp);
}
