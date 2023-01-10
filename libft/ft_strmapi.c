/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:54:50 by jeykim            #+#    #+#             */
/*   Updated: 2023/01/10 15:41:39 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ml;
	int		i;

	if (!s)
		return (0);
	ml = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ml == 0)
		return (0);
	i = 0;
	while (s[i])
	{
		ml[i] = f(i, s[i]);
		i++;
	}
	ml[i] = '\0';
	return (ml);
}
