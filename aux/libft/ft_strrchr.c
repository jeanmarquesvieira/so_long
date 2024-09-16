/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:48:37 by jalves-v          #+#    #+#             */
/*   Updated: 2024/04/20 10:34:31 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*output;
	int				s_len;
	unsigned char	c_unsigned;

	c_unsigned = c;
	output = (char *)s;
	s_len = ft_strlen(output);
	while (s_len >= 0)
	{
		if (output[s_len] == c_unsigned)
			return (&output[s_len]);
		s_len--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char test[] = "abcdecefg";
// 	printf("%s\n", ft_strrchr(test, 'c'));
// 	return (0);
// }
