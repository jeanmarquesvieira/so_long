/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:47:34 by jalves-v          #+#    #+#             */
/*   Updated: 2024/10/04 19:19:18 by jalves-v         ###   ########.fr       */
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
