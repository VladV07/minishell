/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:26:19 by stapioca          #+#    #+#             */
/*   Updated: 2022/08/10 18:41:55 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <readline/readline.h>
# include "libft/libft.h"

typedef struct s_list{
	int				data;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_data{
	char		comands[7];
	char		**env;
	t_list		env_list;
	int			stop_flag;
}	t_data;

char	*ft_readline(char *p);
char	*ft_strjoin_free(char *s1, char const *s2);

#endif