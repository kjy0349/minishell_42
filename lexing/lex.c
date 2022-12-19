/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 19:44:22 by ahel-bah          #+#    #+#             */
/*   Updated: 2022/12/19 18:52:17 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	is_space(char *buff, t_lex *lex, t_list **arg)
{
	lex->argstart = lex->i;
	lex->arglen = lex->i + 1;
	while (buff[lex->i] == ' ')
		lex->i++;
	ft_lstadd_back(arg,
		ft_lstnew(ft_substr_lex(buff, lex->argstart, lex->arglen), 0));
}

int	lex(char *buff, t_list **arg, t_env *env)
{
	t_lex	lex;
	t_list	*tmp;

	lex.i = 0;
	while (buff[lex.i])
	{
		if (buff[lex.i] == ' ')
			is_space(buff, &lex, arg);
		if (buff[lex.i] == '\'')
			if (single_quoting(buff, &lex, arg))
				return (1);
		if (buff[lex.i] == '"')
			if (double_quoting(buff, &lex, arg))
				return (1);
		collect_args(buff, &lex, arg);
	}
	tmp = *arg;
	clean_line(&tmp, env);
	concatenate(arg);
	del_spaces(arg);
	return (ft_errors(*arg));
}
