/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:47:41 by jalves-v          #+#    #+#             */
/*   Updated: 2024/04/18 13:41:07 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;

	if (n == 0)
		return (0);
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (*us1 == *us2 && --n > 0)
	{
		us1++;
		us2++;
	}
	return (*us1 - *us2);
}

// #include <string.h>

// int	main(void)
// {
// 	char s1[] = "abcx";
// 	char s2[] = "abcd";
// 	printf("%i\n", ft_memcmp(s1, s2, 4));
// 	printf("%i\n", memcmp(s1, s2, 4));
// 	return (0);
// }
