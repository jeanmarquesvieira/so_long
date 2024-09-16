/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:48:19 by jalves-v          #+#    #+#             */
/*   Updated: 2024/04/19 17:55:16 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output_str;
	int		output_len;

	if (!s1 || !s2)
		return (NULL);
	output_len = ft_strlen(s1) + ft_strlen(s2);
	output_str = malloc((sizeof(char) * (output_len)) + 1);
	if (!output_str)
		return (NULL);
	while (*s1)
	{
		*output_str = *s1;
		s1++;
		output_str++;
	}
	while (*s2)
	{
		*output_str = *s2;
		s2++;
		output_str++;
	}
	*output_str = '\0';
	return (output_str - output_len);
}

// int	main(void)
// {
// 	char const s1[] = "lorem ipsum";
// 	char const s2[] = " dolor sit amet";
// 	printf("%s\n", ft_strjoin(s1, s2));
// 	return (0);
// }
