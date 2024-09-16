/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:48:25 by jalves-v          #+#    #+#             */
/*   Updated: 2024/04/18 14:26:44 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	while (*src && dstsize > 1)
	{
		*dst = *src;
		dst++;
		src++;
		dstsize--;
	}
	if (dstsize >= 1)
		*dst = '\0';
	return (src_len);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char src[] = "this is a test";
// 	char dest[] = "abc";
// 	printf("%zu\n", ft_strlcpy(dest, src, 4));
// 	printf("%s\n", dest);
// 	return (0);
// }
