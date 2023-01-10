/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:54:50 by jeykim            #+#    #+#             */
/*   Updated: 2023/01/10 15:40:45 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*casts1;
	unsigned char	*casts2;

	i = 0;
	casts1 = (unsigned char *)s1;
	casts2 = (unsigned char *)s2;
	while (i < n)
	{
		if (casts1[i] != casts2[i])
		{
			return (casts1[i] - casts2[i]);
		}
		i++;
	}
	return (0);
}
