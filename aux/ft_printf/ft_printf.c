/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:33:38 by jalves-v          #+#    #+#             */
/*   Updated: 2024/05/04 17:34:23 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_pointer(unsigned long address)
{
	int	i;

	i = 0;
	if (address)
	{
		i += ft_putstr("0x");
		return (i + ft_putnbrhex((address), 'x'));
	}
	return (ft_putstr("(nil)"));
}

static int	ft_print_data(char data_type, va_list *args)
{
	int	count_chars;

	count_chars = 0;
	if (data_type == 'c')
		return (count_chars += ft_putchar(va_arg(*args, int)));
	else if (data_type == 's')
		return (count_chars += ft_putstr(va_arg(*args, char *)));
	else if (data_type == 'p')
		return (count_chars += ft_print_pointer(va_arg(*args, unsigned long)));
	else if (data_type == 'd' || data_type == 'i')
		return (count_chars += ft_putnbr(va_arg(*args, int)));
	else if (data_type == 'u')
		return (count_chars += ft_putnbr_unsigned(va_arg(*args, unsigned int)));
	else if (data_type == 'x' || data_type == 'X')
		return (count_chars += ft_putnbrhex_uint(va_arg(*args, long),
				data_type));
	else if (data_type == '%')
		return (count_chars += ft_putchar('%'));
	return (count_chars);
}

static int	specifier_character(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *formatted_str, ...)
{
	int		count_chars;
	va_list	args;

	if (!formatted_str)
		return (-1);
	count_chars = 0;
	va_start(args, formatted_str);
	while (*formatted_str)
	{
		if (*formatted_str == '%')
		{
			formatted_str++;
			if (!specifier_character(*formatted_str))
				return (-1);
			count_chars += ft_print_data(*formatted_str, &args);
		}
		else
			count_chars += ft_putchar(*formatted_str);
		formatted_str++;
	}
	va_end(args);
	return (count_chars);
}
