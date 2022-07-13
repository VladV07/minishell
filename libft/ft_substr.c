/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:21:47 by stapioca          #+#    #+#             */
/*   Updated: 2021/10/24 20:21:47 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size_s;
	size_t	i;
	size_t	j;
	char	*str;

	size_s = 0;
	str = NULL;
	if (s == NULL)
		return (NULL);
	while (s[size_s] != '\0')
		size_s++;
	if (start > size_s)
		return (ft_strdup(""));
	if (size_s < len)
		len = size_s;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (i < (size_t)start + len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
