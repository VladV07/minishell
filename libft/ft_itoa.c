/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:19:35 by stapioca          #+#    #+#             */
/*   Updated: 2021/10/26 20:33:16 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*nb_zero(char *str_n)
{
	str_n = (char *)malloc(2);
	if (str_n == NULL)
		return (NULL);
	str_n[0] = '0';
	str_n[1] = '\0';
	return (str_n);
}

static char	*nb_do2(int i, int j, char tp[16], char *str_n)
{
	while (i - 1 > 0)
	{
		str_n[j] = tp[i - 1] + '0';
		i--;
		j++;
	}
	str_n[j] = '\0';
	return (str_n);
}

static char	*nb_do1(int j, char tp[16], char *str_n, long int nb)
{
	int	i;

	i = 1;
	while (nb)
	{
		tp[i] = nb % 10;
		nb /= 10;
		i++;
	}
	str_n = (char *)malloc(i - j + 1);
	if (str_n == NULL)
		return (NULL);
	j = 0;
	if (tp[0] == '-')
	{
		str_n[0] = tp[0];
		j = 1;
	}
	str_n = nb_do2(i, j, tp, str_n);
	return (str_n);
}

char	*ft_itoa(int n)
{
	int			i;
	int			j;
	char		tp[16];
	char		*str_n;
	long int	nb;

	str_n = NULL;
	nb = n;
	i = 0;
	j = 1;
	tp[0] = '0';
	if (nb == 0)
		return (nb_zero(str_n));
	if (nb < 0)
	{
		nb = ~nb + 1;
		tp[0] = '-';
		j = 0;
	}
	i++;
	str_n = nb_do1(j, tp, str_n, nb);
	return (str_n);
}
