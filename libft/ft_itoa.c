/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:51:37 by ttavares          #+#    #+#             */
/*   Updated: 2022/11/22 11:20:18 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_nbrsize(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	if (n == 0)
		size++;
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static int	ft_nbrflip(int n)
{
	if (n == -2147483648)
	{
			n++;
			n *= -1;
	}
	else if (n < 0)
		n *= -1;
	return (n);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		size;
	int		nbr;
	int		i;

	size = ft_nbrsize(n);
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (0);
	nbr = ft_nbrflip(n);
	i = size - 1;
	ptr[size] = '\0';
	while (nbr > 0)
	{
		ptr[i] = nbr % 10 + '0';
		nbr /= 10;
		i--;
	}
	if (n == -2147483648)
		ptr[10] = '8';
	if (n == 0)
		ptr[0] = '0';
	if (n < 0)
		ptr[0] = '-';
	return (ptr);
}
