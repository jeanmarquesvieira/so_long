/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:48:41 by jalves-v          #+#    #+#             */
/*   Updated: 2024/04/19 18:08:01 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	int				count;
	size_t			s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	count = len;
	sub = malloc(sizeof(char) * (len) + 1);
	if (!sub)
		return (NULL);
	while (--count >= 0 && start < s_len)
	{
		*sub = s[start];
		start++;
		sub++;
	}
	*sub = '\0';
	return (sub - len);
}

// int	main(void)
// {
// 	char const *s = "lorem ipsum dolor sit amet";
// 	printf("dolor\n");
// 	printf("%s\n", ft_substr(s, 12, 5));
// 	return (0);
// }