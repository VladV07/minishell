/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:04:53 by njohanne          #+#    #+#             */
/*   Updated: 2022/09/12 17:23:47 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_echo(char **str)
{
	int	i;
	int	n;

	i = 1;
	n = 1;
	if (!str[1])
		return (0);
	while (ft_strcmp(str[i], "-n") == 0)
	{
		n = 0;
		i++;
	}
	while (str[i])
	{
		printf("%s", str[i]);
		if (str[++i])
			printf(" ");
	}
	if (n == 1)
		printf("\n");
	printf ("!!!!!!!!!!!!!!!!!!!!echo!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	return (0);
}
