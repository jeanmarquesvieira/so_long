/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:48:13 by jalves-v          #+#    #+#             */
/*   Updated: 2024/04/20 09:09:56 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*s1_dup;

	if (!s1)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s1_dup = malloc(sizeof(char) * s1_len + 1);
	if (!s1_dup)
		return (NULL);
	while (*s1)
	{
		*s1_dup = *s1;
		s1++;
		s1_dup++;
	}
	*s1_dup = '\0';
	return (s1_dup - s1_len);
}

// int	main(void)
// {
// 	char *my_test = ft_strdup("hello, world!");
// 	char *o_test = strdup("hello, world!");
// 	printf("string: %s size: %zu\n", my_test, ft_strlen(my_test));
// 	printf("string: %s size: %zu\n", o_test, ft_strlen(o_test));
// 	free(o_test);
// 	free(my_test);
// 	return (0);
// }
