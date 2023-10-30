/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:39:24 by ttavares          #+#    #+#             */
/*   Updated: 2022/12/05 16:51:41 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrsize(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size++;
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char				*ptr;
	unsigned int		size;
	unsigned int		nbr;
	unsigned int		i;

	size = ft_nbrsize(n);
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (0);
	nbr = n;
	i = size - 1;
	ptr[size] = '\0';
	while (nbr > 0)
	{
		ptr[i] = nbr % 10 + '0';
		nbr /= 10;
		i--;
	}
	if (n == 0)
		ptr[0] = '0';
	return (ptr);
}
