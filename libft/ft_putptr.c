/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:53:35 by ttavares          #+#    #+#             */
/*   Updated: 2022/12/06 15:04:40 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_convert(unsigned long long num)
{
	if (num <= 9)
		ft_putchar(num + '0');
	else if (num >= 16)
	{
		ft_print_convert(num / 16);
		ft_print_convert(num % 16);
	}
	else
		ft_putchar(num - 10 + 'a');
}

int	ft_putptr(unsigned long long num)
{
	int	total;

	total = 0;
	if (num == 0)
	{
		write(1, "(nil)", 5);
		return (total + 5);
	}
	else
	{
		write(1, "0x", 2);
		ft_print_convert(num);
	}
	while (num != 0)
	{
		total++;
		num = num / 16;
	}
	return (total + 2);
}
