/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 22:29:39 by njohanne          #+#    #+#             */
/*   Updated: 2022/10/01 00:08:15 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_sort_env(char **senv)
{
	char	*str;
	int		k;
	int		i;
	int		sr;

	i = 0;									//переменная которая идет по строкам
	sr = 0;									//переменная учитывающая сколько было перестановок
	while(1)
	{
		k = ft_strcmp(senv[i], senv[i + 1]);//сравниваем строчку и следующую
		if (k > 0)							//если больше то меняем их местами
		{
			str = senv[i];
			senv[i] = senv[i + 1];
			senv[i + 1] = str;
			sr++;							//увеличиваем счетчик перестановок
		}
		i++;								//увеличивает строчку
		if (!senv[i + 1] && sr == 0)		//если после нее идет нулл, то это была последняя строчка
			return(senv);					//и если количество изменений было 0 то возвращаем отсортированный список
		else if (!senv[i + 1])
		{				//если после идет нулл, то это последняя строчка
			sr = 0;
			i = 0;
		}							//обнуляем переменную перестановок, и начинаем все заново
	}
	return(senv);
}

int	ft_print_env(void)
{
	char	**senv;
	int		len;
	int		i;
	
	len = ft_len_env(g_sh.env);
	senv = (char **)malloc(sizeof(char **) * (len + 1));
	senv[len] = NULL;
	i = -1;
	while (g_sh.env[++i])
	{
		len = ft_strlen(g_sh.env[i]);
		senv[i] = (char *)malloc(sizeof(char *) * len);
		senv[i] = ft_memcpy(senv[i], g_sh.env[i], len);
	}
	senv = ft_sort_env(senv);
	i = -1;
	while (senv[++i])
		printf("%s\n", senv[i]);
	ft_free_env(senv);
	return(0);
}
