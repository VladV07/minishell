/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_slesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:34:18 by stapioca          #+#    #+#             */
/*   Updated: 2022/08/10 21:03:39 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_slesh(char *str, int *i)
{
	int		nb_slesh;
	char	*str_tmp1;
	char	*str_tmp2;

	nb_slesh = *i;
	str_tmp1 = ft_substr(str, 0, nb_slesh);
	str_tmp2 = ft_strdup(str + nb_slesh + 1);
	str_tmp1 = ft_strjoin(str_tmp1, str_tmp2);
	free(str_tmp2);
	free(str);
	(*i)++;
	printf("get_slesh: str_tmp1 = %s\n", str_tmp1);
	return (str_tmp1);
}
