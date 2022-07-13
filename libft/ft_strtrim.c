/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:21:44 by stapioca          #+#    #+#             */
/*   Updated: 2021/10/26 20:35:00 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static long int	start_strtrim(char const *s1, char const *set)
{
	long int	i;
	long int	start;
	long int	j;

	i = 0;
	start = 0;
	while (s1[i] != '\0')
	{
		if (i != start)
			return (start);
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				start++;
				break ;
			}
			else
				j++;
		}
		i++;
	}
	return (start);
}

static long int	do_end_strtrim(char const *s1, char const *set, \
						long int size_s1, long int end)
{
	long int	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (s1[size_s1 - 1] == set[j])
		{
			end--;
			break ;
		}
		else
			j++;
	}
	return (end);
}

static long int	end_strtrim(char const *s1, char const *set)
{
	long int	size_s1;
	long int	end;

	size_s1 = 0;
	while (s1[size_s1] != '\0')
		size_s1++;
	if (size_s1 == 0)
		return (0);
	end = size_s1 - 1;
	if (end <= 0)
		return (0);
	while (size_s1 - 1 >= 0)
	{
		if (size_s1 - 1 != end)
			return (end);
		end = do_end_strtrim(s1, set, size_s1, end);
		size_s1--;
	}
	return (end);
}

static void	ft_do(char const *s1, char *str, long int start, long int end)
{	
	long int	i;

	i = 0;
	while (start <= end)
	{
		str[i] = s1[start];
		start++;
		i++;
	}
	str[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	long int	start;
	long int	end;

	str = NULL;
	start = 0;
	end = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	start = start_strtrim(s1, set);
	end = end_strtrim(s1, set);
	if ((start == 0 && end == 0) || start > end)
	{
		str = malloc(1);
		str[0] = '\0';
		return (str);
	}
	else
		str = malloc(end - start + 2);
	if (str == NULL)
		return (NULL);
	ft_do(s1, str, start, end);
	return (str);
}
