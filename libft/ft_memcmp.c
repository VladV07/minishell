/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:19:43 by stapioca          #+#    #+#             */
/*   Updated: 2021/10/24 20:19:44 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tp1;
	unsigned char	*tp2;

	tp1 = (unsigned char *)s1;
	tp2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (tp1[i] != tp2[i])
			return (tp1[i] - tp2[i]);
		i++;
	}
	return (0);
}
