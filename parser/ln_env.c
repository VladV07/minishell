/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ln_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:22:24 by stapioca          #+#    #+#             */
/*   Updated: 2022/08/10 18:46:22 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ln_env(char *env_j)
{
	int	i;

	i = 0;
	while (env_j[i] != '=' && env_j[i] != '\0')
		i++;
	return (i);
}
