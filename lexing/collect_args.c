/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:34:03 by jeykim            #+#    #+#             */
/*   Updated: 2023/01/10 15:44:34 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	collect_args(char *buff, t_lex *lex, t_list **arg)
{
	int	i;

	i = 0;
	while (buff[lex->i] && buff[lex->i] != '\''
		&& buff[lex->i] != '"' && buff[lex->i] != ' ')
	{
		if (i++ == 0)
			lex->argstart = lex->i;
		lex->i++;
	}
	lex->arglen = lex->i;
	if (i > 0)
		ft_lstadd_back(arg,
			ft_lstnew(ft_substr_lex(buff, lex->argstart, lex->arglen), 0));
}
