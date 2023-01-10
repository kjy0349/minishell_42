/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_opp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 21:34:25 by jeykim            #+#    #+#             */
/*   Updated: 2023/01/10 15:46:51 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_opp(t_list *arg)
{
	if (ft_strcmp(arg->content, "<<") == 0
		|| ft_strcmp(arg->content, ">>") == 0
		|| ft_strcmp(arg->content, "|") == 0
		|| ft_strcmp(arg->content, "<") == 0
		|| ft_strcmp(arg->content, ">") == 0)
		return (1);
	return (0);
}
