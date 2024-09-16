/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:48:10 by jalves-v          #+#    #+#             */
/*   Updated: 2024/04/20 10:29:16 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *s, int c)
{
	size_t			len;
	unsigned char	c_unsigned;

	c_unsigned = c;
	len = ft_strlen(s);
	if (c_unsigned == '\0')
		return ((char *)&s[len]);
	while (*s)
	{
		if (*s == c_unsigned)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char s1[] = "abcdefghijklmno";
// 	printf("%s\n", ft_strchr(s1, 'm'));
// 	return (0);
// }
