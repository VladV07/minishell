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

PARSER = parser/

LIST =  minishell.c \
		ft_lstclear.c \
		ft_lstlast.c \
		ft_lstnew.c \
		ft_pushback.c \
		ft_readline.c \
		ft_strjoin_free.c \
		lexer.c \
		$(PARSER)get_dollar.c \
		$(PARSER)get_double_quotes.c \
		$(PARSER)get_in_env.c \
		$(PARSER)get_quote.c \
		$(PARSER)get_slesh.c \
		$(PARSER)is_key.c \
		$(PARSER)ln_env.c \
		$(PARSER)parser.c \
		executor.c \
		free_and_exit.c \
		ft_strcmp.c \
		command/ft_echo.c


LIBFT = ./libft/libft.a 

READLINE = -lreadline

OBJS = $(patsubst %.c,%.o,$(LIST))

FLAGS = -Wall -Wextra -Werror -g

.PHONY : all clean fclean re

all : lib $(NAME) $(HEADER)

lib :
	@make -C ./libft

$(NAME) : $(OBJS)
	cc $(FLAGS) $(OBJS) $(LIBFT) $(READLINE) -I $(HEADER) -o $@

%.o : %.c $(HEADER)
	cc $(FLAGS) -c $< -o $@ -I ${HEADER}

clean :
	@rm -f $(OBJS)
	@make clean -C libft

fclean : clean
	@rm -f $(NAME)
	@make fclean -C libft

re : fclean all