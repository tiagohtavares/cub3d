/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:23:49 by ttavares          #+#    #+#             */
/*   Updated: 2022/11/21 16:42:34 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!big && len == 0)
	{
		return (0);
	}
	if (!little[0])
	{
		return ((char *)big);
	}
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i] && little[j] && i + j < len && big[i + j] == little[j])
			j++;
		if (!little[j])
		{
			return ((char *)(big + i));
		}
		i++;
	}
	return (0);
}
