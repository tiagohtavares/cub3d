/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:29:54 by ttavares          #+#    #+#             */
/*   Updated: 2022/11/21 16:42:14 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char*restrict dst, const char*restrict src, size_t dstsize)
{
	size_t	i;
	size_t	c;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	c = 0;
	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize == 0 || dstsize <= destlen)
		return (dstsize + srclen);
	if (!dst)
		return (srclen);
	while (dst[i] != '\0')
		i++;
	while (src[c] != '\0' && c < dstsize -1 - destlen)
	{
		dst[i] = src[c];
		i++;
		c++;
	}
	dst[i] = '\0';
	return (destlen + srclen);
}
