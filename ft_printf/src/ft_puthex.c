/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:00:12 by yboumlak          #+#    #+#             */
/*   Updated: 2024/01/04 19:34:23 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_puthex(unsigned long n, char c)
{
	int		r;
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	r = 0;
	if (n >= 16)
	{
		r += ft_puthex(n / 16, c);
	}
	r += ft_putchar(base[n % 16]);
	return (r);
}
