/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:47:57 by jalves-v          #+#    #+#             */
/*   Updated: 2024/04/09 16:03:48 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	long_n;

	long_n = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		long_n *= -1;
	}
	if (long_n > 9)
	{
		ft_putnbr_fd(long_n / 10, fd);
		ft_putchar_fd(long_n % 10 + 48, fd);
	}
	else
		ft_putchar_fd(long_n + 48, fd);
}

// #include <limits.h>

// int	main(void)
// {
// 	int fd = 1;
// 	ft_putnbr_fd(INT_MIN, fd);
// 	write(fd, "\n", 1);
// 	ft_putnbr_fd(0, fd);
// 	write(fd, "\n", 1);
// 	ft_putnbr_fd(INT_MAX, fd);
// 	write(fd, "\n", 1);
// 	return (0);
// }
