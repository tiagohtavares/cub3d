/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:23:26 by ttavares          #+#    #+#             */
/*   Updated: 2022/12/06 14:55:34 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_convert(unsigned int num)
{
	if (num <= 9)
		ft_putchar(num + '0');
	else if (num >= 16)
	{
		ft_print_convert(num / 16);
		ft_print_convert(num % 16);
	}
	else
		ft_putchar(num - 10 + 'A');
}

int	ft_puthex_upper(unsigned int num)
{
	int	total;

	total = 0;
	if (num == 0)
	{
		ft_putchar('0');
		total++;
	}
	else
		ft_print_convert(num);
	while (num != 0)
	{
		num = num / 16;
		total++;
	}
	return (total);
}
