/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:54:50 by jeykim            #+#    #+#             */
/*   Updated: 2023/01/10 15:41:29 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;
	size_t	srcsize;
	size_t	srcbefore;

	i = 0;
	srcsize = 0;
	srcbefore = 0;
	while (dst[i] != '\0')
		i++;
	while (src[srcsize] != '\0')
		srcsize++;
	if (dstsize < i)
		return (dstsize + srcsize);
	k = srcsize + i;
	while (src[srcbefore] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[srcbefore];
		i++;
		srcbefore++;
	}
	dst[i] = '\0';
	return (k);
}
