/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 11:34:45 by jeykim            #+#    #+#             */
/*   Updated: 2023/01/10 15:49:02 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static bool	overflow(uint64_t parse, int8_t sign, char c)
{
	static const uint64_t	pos_max = 0x7fffffffffffffff;
	static const uint64_t	neg_max = 0x8000000000000000;
	uint64_t				cutoff;
	int						max_val;

	if (sign == 1)
		cutoff = pos_max;
	else
		cutoff = neg_max;
	max_val = (int)(cutoff % 10u) + '0';
	cutoff /= 10;
	return (parse > cutoff || (parse == cutoff && c > max_val));
}

static int	exit_with_arg(char **content)
{
	int			i;
	int			sign;
	uint64_t	parse;

	i = 0;
	parse = 0;
	sign = 1;
	if (content[1][i] == '-')
		sign = -1;
	if (content[1][i] == '-' || content[1][i] == '+')
		i++;
	while (i < (int)ft_strlen(content[1]))
	{
		if (!ft_isdigit(content[1][i]) ||
			(ft_isdigit(content[1][i]) && overflow(parse, sign, content[1][i])))
		{
			write(2, "minishell: exit: ", 17);
			write(2, content[1], ft_strlen(content[1]));
			write(2, ": numeric argument required\n", 28);
			return (255);
		}
		parse *= 10;
		parse += content[1][i++] - '0';
	}
	return (ft_atoi(content[1]));
}

int	ft_exit(char **content, t_env *env)
{
	printf("exit\n");
	if (ft_dubstrlen(content) > 2)
	{
		write(2, "minishell: exit: too many arguments\n", 36);
		g_exit_status = 1;
		return (255);
	}
	ft_free_env(env);
	if (ft_dubstrlen(content) == 2)
		exit(exit_with_arg(content));
	exit(0);
	return (0);
}
