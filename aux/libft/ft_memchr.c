/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:47:39 by jalves-v          #+#    #+#             */
/*   Updated: 2024/04/18 12:28:11 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*u;
	size_t			i;

	u = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (u[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
// #include <string.h>

// int	main(void)
// {
// 	char s[] = "testx";
// 	char *result = ft_memchr(s, 'x', 5);
// 	char *result2 = memchr(s, 'x', 5);
// 	printf("%s\n", result);
// 	printf("%s\n", result2);
// 	return (0);
// }
