# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 19:16:05 by bkristen          #+#    #+#              #
#    Updated: 2022/10/11 00:08:50 by vlad             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

PARSER = parser/

COMMAND = command/

EXECUTOR = executor/

SRC			=	minishell.c \
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
			free_and_exit.c \
			ft_strcmp.c \
			$(COMMAND)ft_echo.c \
			$(COMMAND)ft_pwd.c \
			$(COMMAND)ft_env.c \
			$(COMMAND)ft_export.c \
			$(COMMAND)ft_unset.c \
			$(COMMAND)ft_free_env.c \
			$(COMMAND)ft_cd.c \
			$(COMMAND)ft_work_env.c \
			$(COMMAND)ft_print_env.c \
			$(COMMAND)ft_unset_cpy.c \
			$(COMMAND)ft_norm_help.c \
			$(COMMAND)ft_exit.c \
			$(EXECUTOR)do_herdog.c \
			$(EXECUTOR)do_redirections.c \
			$(EXECUTOR)executor.c \
			$(EXECUTOR)do_command.c \
#			signal.c \

HEADER		=	minishell.h

CC			=	cc

FLAGS		=	-Wall -Werror -Wextra -g #-I$(HEADER) -I/Users/$(USER)/.brew/Cellar/readline/8.1.2/include

RM			=	rm -f

OBJ			= $(SRC:.c=.o)

all : libft $(NAME)
	stty -ctlecho

$(NAME) : $(OBJ) 
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -lreadline -L./libft -lft 

%.o: %.c $(HEADER) Makefile
	$(CC) $(FLAGS) -c $< -o $@

libft :
	make -C libft

clean :
	make -C libft clean
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)
	$(RM) libft/libft.a

re : fclean all

.PHONY: all clean fclean re libft
