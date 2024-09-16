/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:47:34 by jalves-v          #+#    #+#             */
/*   Updated: 2024/04/19 18:01:52 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_digits(int n)
{
	int		digits;
	long	numb;

	digits = 1;
	numb = n;
	while (numb / 10 != 0)
	{
		digits++;
		numb /= 10;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	int		count_digits;
	long	n_long;

	n_long = n;
	count_digits = check_digits(n);
	if (n < 0)
	{
		count_digits++;
		n_long *= -1;
	}
	itoa = malloc((sizeof(char) * count_digits) + 1);
	if (!itoa)
		return (NULL);
	itoa[count_digits] = '\0';
	while (count_digits-- > 0)
	{
		itoa[count_digits] = n_long % 10 + 48;
		n_long /= 10;
	}
	if (n < 0)
		itoa[++count_digits] = '-';
	return (itoa);
}

// #include <limits.h>
// int	main(int argc, char **argv)
// {
// 	// if (argc == 2)
// 	// 	printf("%s\n", ft_itoa(ft_atoi(argv[1])));
// 	(void)argc;
// 	(void)argv;
// 	printf("%s <> %s\n", ft_itoa(INT_MIN), ft_itoa(INT_MAX));
// 	printf("%d <> %d\n", INT_MIN, INT_MAX);
// 	printf("-6792: %s\n", ft_itoa(-6792));
// 	printf("0: %s\n", ft_itoa(0));
// 	return (0);
// }
