/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:15:37 by yboumlak          #+#    #+#             */
/*   Updated: 2024/01/23 19:26:20 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	formatter(va_list args, char c)
{
	int	length;

	length = 0;
	if (c == 'c')
		length += ft_putchar(va_arg(args, int));
	else if (c == 's')
		length += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
	{
		length += ft_putstr("0x");
		length += ft_puthex(va_arg(args, unsigned long), 'x');
	}
	else if (c == 'd' || c == 'i')
		length += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		length += ft_putnbr(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		length += ft_puthex(va_arg(args, unsigned int), c);
	else if (c == '%')
		length += ft_putchar('%');
	return (length);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		length;
	int		i;

	length = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	va_start(args, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			length += formatter(args, s[i]);
		}
		else if (s[i] != '%')
			length += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (length);
}
