/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:59:07 by ttavares          #+#    #+#             */
/*   Updated: 2022/11/21 16:42:41 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	c;
	size_t	j;

	if (!s1 || !set)
	{
		return (0);
	}
	c = 0;
	while (s1[c] && ft_check(s1[c], set))
		c++;
	j = ft_strlen(s1);
	while (j > c && ft_check(s1[j - 1], set))
		j--;
	ptr = malloc(sizeof(char) *(j - c + 1));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1 + c, j - c + 1);
	return (ptr);
}
