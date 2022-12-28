# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 15:18:51 by ahel-bah          #+#    #+#              #
#    Updated: 2022/12/28 17:46:16 by jeykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
NAME = minishell
RM = rm -rf
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = minishell.c \
\
	  execution/built-ins/ft_env.c execution/built-ins/ft_exit.c\
	  execution/exec_multi_cmd.c execution/built-ins/ft_echo.c\
	  execution/built-ins/ft_pwd.c execution/lst_to_array.c \
	  execution/exec_builtins.c execution/built-ins/ft_cd.c\
	  execution/built-ins/ft_export.c execution/built-ins/ft_unset.c\
	  execution/check_redirections.c\
\
	  include/cmd_include.c include/dubstr_include.c include/env_include.c\
	  include/ft_dellst.c include/ft_error.c include/ft_is_opp.c\
	  include/ft_lstinsert.c include/ft_strcmp.c include/ft_substr_lex.c\
	  include/in_between_include.c include/red_include.c\
\
	  lexing/clean_line.c lexing/collect_args.c lexing/concatenate.c\
	  lexing/define_opp.c lexing/double_quoting.c lexing/single_quoting.c\
	  lexing/ft_herdoc.c lexing/lex.c lexing/spaces.c\
\
	  parsing/ft_errors.c parsing/redirections_parser.c parsing/split_pipe.c\
	  parsing/wildcard.c

OBJ = $(SRC:.c=.o)
	
%.o:%.c
	$(CC) $(CFLAGS) -I $(shell brew --prefix readline)/include -c $< -o $@
	
all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS)  $(OBJ) -L $(shell brew --prefix readline)/lib -lreadline -o \
	$(NAME) $(LIBFT)

$(LIBFT):
	make bonus -C libft

update:
	$(shell cd ~/minishell && brew update)

install:
	$(shell cd ~/minishell && brew install readline)

clean:
	$(RM) $(OBJ)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all
