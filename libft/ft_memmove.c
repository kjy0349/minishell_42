/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:54:50 by jeykim            #+#    #+#             */
/*   Updated: 2023/01/10 15:40:54 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void	*dst, const	void *src, size_t len)
{
	size_t	i;
	char	*castdst;
	char	*castsrc;

	i = 0;
	castdst = (char *)dst;
	castsrc = (char *)src;
	if (dst == 0 && src == 0)
		return (0);
	while (len > 0 && castdst > castsrc)
	{
		castdst[len - 1] = castsrc[len - 1];
		len--;
	}
	while (len > 0)
	{
		castdst[i] = castsrc[i];
		i++;
		len--;
	}
	return (dst);
}
