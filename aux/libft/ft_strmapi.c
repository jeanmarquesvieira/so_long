/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:48:30 by jalves-v          #+#    #+#             */
/*   Updated: 2024/04/19 18:06:58 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;
	size_t			s_len;

	if (!s || !f)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	result = malloc((sizeof(char) * s_len) + 1);
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// char	upper_or_lower(unsigned int i, char c)
// {
// 	(void)i;
// 	if (c >= 65 && c <= 90)
// 		return (c + 32);
// 	else if (c >= 97 && c <= 122)
// 		return (c - 32);
// 	else
// 		return (c);
// }

// int	main(void)
// {
// 	const char test[] = "*tHIS Is a tEst!-";
// 	printf("%s\n", test);
// 	printf("%s\n", ft_strmapi(test, upper_or_lower));
// 	return (0);
// }
