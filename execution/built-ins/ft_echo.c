/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soopark <soopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 22:25:19 by ahel-bah          #+#    #+#             */
/*   Updated: 2022/12/18 17:18:46 by soopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_echo(char **content)
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
	return (0);
}