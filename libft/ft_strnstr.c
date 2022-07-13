/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:21:37 by stapioca          #+#    #+#             */
/*   Updated: 2021/10/24 20:21:38 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	size_needle;
	size_t	size_haystack;
	size_t	i;

	size_needle = ft_strlen((char *)needle);
	size_haystack = ft_strlen((char *)haystack);
	if (size_needle == 0)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	if (size_haystack < size_needle)
		return (NULL);
	i = 0;
	while (i <= len - size_needle)
	{
		if ((haystack[0] == needle[0]) && \
			(0 == ft_strncmp(haystack, needle, size_needle)))
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
