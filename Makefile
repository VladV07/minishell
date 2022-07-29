# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 19:04:36 by stapioca          #+#    #+#              #
#    Updated: 2022/04/20 19:04:36 by stapioca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

HEADER = minishell.h

LIST =  minishell.c \
		ft_lstclear.c \
		ft_lstlast.c \
		ft_lstnew.c \
		ft_pushback.c \
		ft_readline.c

LIBFT = -Llibft -lft

READLINE = -lreadline

OBJS = $(patsubst %.c,%.o,$(LIST))

FLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re

all : $(NAME) $(HEADER)

$(NAME) : $(OBJS)
	cc $(FLAGS) $(OBJS) $(LIBFT) $(READLINE) -I $(HEADER) -o $@

%.o : %.c $(HEADER)
	cc $(FLAGS) -c $< -o $@ -I ${HEADER}

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all