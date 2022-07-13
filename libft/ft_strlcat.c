/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecosting <ecosting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:53:50 by ecosting          #+#    #+#             */
/*   Updated: 2021/10/21 19:53:51 by ecosting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_src = ft_strlen(src);
	len_dst = 0;
	i = 0;
	while (dst[len_dst] && len_dst < size)
		len_dst++;
	while (src[i] && (i + len_dst + 1) < size)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	if (size > len_dst)
		dst[len_dst + i] = '\0';
	return (len_src + ft_min(size, len_dst));
}
