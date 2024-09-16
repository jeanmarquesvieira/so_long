/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:48:34 by jalves-v          #+#    #+#             */
/*   Updated: 2024/04/19 15:48:55 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (!needle[0])
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && (i + needle_len - 1) < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j])
		{
			if (j == needle_len - 1)
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

// #include <string.h>

// int	main(void)
// {
// 	char test[] = "hello, world!";
// 	char find[] = " w";
// 	printf("%s\n", ft_strnstr(test, find, 20));
// 	printf("%s\n", strnstr(test, find, 20));
// 	return (0);
// }
