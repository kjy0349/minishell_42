/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:54:50 by jeykim            #+#    #+#             */
/*   Updated: 2023/01/10 15:41:43 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*casts1;
	unsigned char	*casts2;

	i = 0;
	if (n == 0)
		return (0);
	casts1 = (unsigned char *)s1;
	casts2 = (unsigned char *)s2;
	while (casts1[i] && casts2[i] && i < n - 1 && casts1[i] == casts2[i])
		i++;
	if (casts1[i] > casts2[i])
		return (1);
	if (casts1[i] < casts2[i])
		return (-1);
	return (0);
}
