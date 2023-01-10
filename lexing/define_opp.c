/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_opp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:54:30 by jeykim            #+#    #+#             */
/*   Updated: 2023/01/10 15:45:07 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	reallocate(t_list **arg, char *new)
{
	free((*arg)->content);
	(*arg)->content = new;
}

static void	insert_allocat(t_list **arg, int i)
{
	ft_lstinsert(arg, ft_lstnew(ft_substr_lex((*arg)->content, i,
				ft_strlen((*arg)->content)), 0));
	reallocate(arg, ft_substr_lex((*arg)->content, 0, i));
}

static int	ft_tbd(t_list **arg, int *i, char c)
{
	if ((*i) == 0 && (*arg)->content[(*i)] == c)
	{
		(*i)++;
		if ((*arg)->content[(*i)] == c)
		{
			(*i)++;
			if ((*arg)->content[(*i)] != '\0')
				insert_allocat(arg, (*i));
		}
		else if ((*arg)->content[(*i)])
			insert_allocat(arg, (*i));
		return (1);
	}
	return (0);
}

void	ft_is_redirections(t_list **arg)
{
	int	i;

	i = 0;
	while ((*arg)->quoted == 0 && (*arg)->content[i])
	{
		if (ft_tbd(arg, &i, '<') || ft_tbd(arg, &i, '>'))
			break ;
		else if ((*arg)->content[i] == '>' || (*arg)->content[i] == '<')
		{
			insert_allocat(arg, i);
			break ;
		}
		i++;
	}
}

void	define_pipe(t_list **arg)
{
	int	i;

	i = 0;
	while ((*arg)->quoted == 0 && (*arg)->content[i])
	{
		if (i == 0 && (*arg)->content[i] == '|')
		{
			i++;
			if ((*arg)->content[i])
				insert_allocat(arg, i);
			break ;
		}
		else if ((*arg)->content[i] == '|')
		{
			insert_allocat(arg, i);
			break ;
		}
		i++;
	}
}
