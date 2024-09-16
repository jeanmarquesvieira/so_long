/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:48:22 by jalves-v          #+#    #+#             */
/*   Updated: 2024/04/18 12:38:36 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = 0;
	while (src[i] && i < dstsize - dst_len - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// #include <string.h>

// int	main(void)
// {
// 	char my_func1[14] = "hello, ";
// 	char my_func2[] = "world!";
// 	printf("%zu\n", ft_strlcat(my_func1, my_func2, 14));
// 	printf("%s\n", my_func1);
// 	char o_func1[14] = "hello, ";
// 	char o_func2[] = "world!";
// 	printf("%zu\n", strlcat(o_func1, o_func2, 14));
// 	printf("%s\n", o_func1);
// 	return (0);
// }
