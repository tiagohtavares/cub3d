/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttavares <ttavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:28:37 by ttavares          #+#    #+#             */
/*   Updated: 2022/12/06 13:58:34 by ttavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_format(const char *txt, int i, va_list conv)
{
	if (txt[i] == '%')
		return (ft_putchar(txt[i]));
	else if (txt[i] == 'c')
		return (ft_putchar(va_arg(conv, int)));
	else if (txt[i] == 's')
		return (ft_putstr(va_arg(conv, char *)));
	else if (txt[i] == 'd' || txt[i] == 'i')
		return (ft_putnbr(va_arg(conv, int)));
	else if (txt[i] == 'u')
		return (ft_putnbr_unsigned(va_arg(conv, unsigned int)));
	else if (txt[i] == 'x')
		return (ft_puthex_lower(va_arg(conv, unsigned int)));
	else if (txt[i] == 'X')
		return (ft_puthex_upper(va_arg(conv, unsigned int)));
	else if (txt[i] == 'p')
		return (ft_putptr(va_arg(conv, unsigned long long)));
	return (0);
}

int	ft_printf(const char *txt, ...)
{
	va_list	conv;
	int		i;
	int		totalchar;

	va_start(conv, txt);
	i = 0;
	totalchar = 0;
	while (txt[i])
	{
		if (txt[i] == '%' && ft_strchr("cspdiuxX%", txt[i + 1]))
		{
			totalchar += check_format(txt, i + 1, conv);
			i++;
		}
		else
		{
			totalchar += ft_putchar(txt[i]);
		}
		i++;
	}
	va_end(conv);
	return (totalchar);
}
