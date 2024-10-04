/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:22:20 by jalves-v          #+#    #+#             */
/*   Updated: 2024/05/04 13:57:14 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		printed_digits;
	long	ln;

	ln = n;
	printed_digits = 0;
	if (ln < 0)
	{
		printed_digits += ft_putchar('-');
		ln *= -1;
	}
	if (ln <= 9)
		printed_digits += ft_putchar(ln + 48);
	else
	{
		printed_digits += ft_putnbr(ln / 10);
		printed_digits += ft_putnbr(ln % 10);
	}
	return (printed_digits);
}

int	ft_putnbrhex(unsigned long ln, char upper_or_lower)
{
	char	*hex;
	int		i;

	i = 0;
	if (upper_or_lower == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (ln < 16)
		return (ft_putchar(hex[ln]));
	i += ft_putnbrhex(ln / 16, upper_or_lower);
	return (i + ft_putnbrhex(ln % 16, upper_or_lower));
}

int	ft_putnbrhex_uint(unsigned int ln, char upper_or_lower)
{
	return (ft_putnbrhex((unsigned long)ln, upper_or_lower));
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n < 10)
		return (ft_putchar(n + 48));
	else
	{
		i = (ft_putnbr_unsigned(n / 10));
		return (i + ft_putnbr_unsigned(n % 10));
	}
}
