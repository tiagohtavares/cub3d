/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:11:03 by ttavares          #+#    #+#             */
/*   Updated: 2022/12/06 14:54:51 by ttavares         ###   ########.fr       */
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
		ft_putchar(num - 10 + 'a');
}

int	ft_puthex_lower(unsigned int num)
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
