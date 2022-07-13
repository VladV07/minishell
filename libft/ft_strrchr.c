/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:21:40 by stapioca          #+#    #+#             */
/*   Updated: 2021/10/24 20:21:41 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int ch)
{
	char	*s;
	int		i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == (char)ch)
		{
			s = ((char *)str);
			i = 1;
		}
		str++;
	}
	if (ch == '\0' && str)
		return ((char *)str);
	if (i == 1)
		return (s);
	return ((void *)0);
}
