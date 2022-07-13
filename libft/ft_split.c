/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:20:15 by stapioca          #+#    #+#             */
/*   Updated: 2021/10/26 20:33:55 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	**ft_clear(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static size_t	ft_strlen_c(const char *str, char c)
{
	size_t			i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static size_t	ft_count_words(const char *str, char c)
{
	size_t			i;
	size_t			count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i] != c && str[i + 1] && str[i + 1] == c) \
							|| (str[i] != c && !str[i + 1]))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t			i;
	size_t			start;
	char			**array;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	array = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (s[i++] == c)
		start++;
	i = -1;
	while (++i < ft_count_words(s, c))
	{
		array[i] = ft_substr(s, start, ft_strlen_c(&s[start], c));
		if (!array[i])
			return (ft_clear(array));
		start += ft_strlen_c(&s[start], c);
		while (s[start] == c)
			start++;
	}
	array[i] = NULL;
	return (array);
}
