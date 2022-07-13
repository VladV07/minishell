/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:21:18 by stapioca          #+#    #+#             */
/*   Updated: 2021/10/24 20:21:19 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		if ((dstsize != 0) && (i < (dstsize - 1)))
		{
			dst[i] = src[i];
			j++;
		}
		i++;
	}
	if (dstsize != 0)
		dst[j] = '\0';
	return (i);
}
