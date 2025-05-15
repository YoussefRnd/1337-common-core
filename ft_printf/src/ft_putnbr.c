/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:02:40 by yboumlak          #+#    #+#             */
/*   Updated: 2024/01/04 19:25:23 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr(long long nb)
{
	int	r;

	r = 0;
	if (nb < 0)
	{
		r += write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		r += ft_putnbr(nb / 10);
	}
	r += ft_putchar(nb % 10 + 48);
	return (r);
}
