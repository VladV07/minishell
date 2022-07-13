/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:21:11 by stapioca          #+#    #+#             */
/*   Updated: 2021/10/26 20:34:15 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/signal.h>

static char	*do_s2(char const *s2, unsigned int	size_s2, \
				unsigned int	i, char *str)
{
	unsigned int	j;

	j = 0;
	while (j < size_s2)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	size_s1;
	unsigned int	size_s2;
	unsigned int	i;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = 0;
	while (s1[size_s1] != '\0')
		size_s1++;
	size_s2 = 0;
	while (s2[size_s2] != '\0')
		size_s2++;
	str = malloc(size_s1 + size_s2 + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < size_s1)
	{
		str[i] = s1[i];
		i++;
	}
	str = do_s2(s2, size_s2, i, str);
	return (str);
}
