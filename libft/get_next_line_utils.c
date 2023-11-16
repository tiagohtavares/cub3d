/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:07:32 by ttavares          #+#    #+#             */
/*   Updated: 2023/11/16 11:12:20 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char*restrict dst, const char*restrict src, size_t dstsize)
{
	size_t	i;
	size_t	c;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	c = 0;
	if (!dst && dstsize == 0)
		return (ft_strlen_gnl(src));
	destlen = ft_strlen_gnl(dst);
	srclen = ft_strlen_gnl(src);
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

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*ptr;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	ptr = malloc(sizeof(char) *(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!ptr)
		return (0);
	ft_strlcpy_gnl(ptr, s1, ft_strlen_gnl(s1) + 1);
	ft_strlcat(ptr, s2, ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	free (s1);
	return (ptr);
}

int	find_linebreaker(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	l = ft_strlen_gnl(src);
	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (l);
}
