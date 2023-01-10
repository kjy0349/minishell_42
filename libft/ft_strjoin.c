/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:54:50 by jeykim            #+#    #+#             */
/*   Updated: 2023/01/10 15:41:26 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	char	*al;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	al = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (al == 0)
		return (0);
	i = 0;
	j = 0;
	while (i <= ft_strlen(s1) + ft_strlen(s2))
	{
		while (i < ft_strlen(s1))
		{
			al[i] = s1[i];
			i++;
		}
		al[i] = s2[j];
		i++;
		j++;
	}
	al[i] = '\0';
	return (al);
}
