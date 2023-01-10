/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:25:19 by jeykim            #+#    #+#             */
/*   Updated: 2023/01/10 15:37:14 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_echo(char **content)
{
	int	i;
	int	yes;

	i = 1;
	yes = 0;
	while (ft_ncmp(content[i]) == 0)
	{
		i++;
		yes++;
		if (content[i] && !ft_strcmp(content[i], " "))
			i++;
	}
	while (content[i])
	{
		write(1, content[i], ft_strlen(content[i]));
		i++;
	}
	if (yes == 0)
		write(1, "\n", 1);
	g_exit_status = 0;
}
