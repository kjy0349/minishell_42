/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:53:14 by jeykim            #+#    #+#             */
/*   Updated: 2023/01/10 15:47:56 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	list_size(t_env *lst)
{
	int		i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

char	**lst_to_array(t_env *env, char *save)
{
	t_env	*tmp;
	char	**array;
	int		i;

	tmp = env;
	i = list_size(tmp);
	array = (char **)malloc(sizeof(char *) * (i + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (tmp)
	{
		save = ft_strjoin("=", tmp->content);
		array[i] = ft_strjoin(tmp->name, save);
		// free(save);
		tmp = tmp->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}
