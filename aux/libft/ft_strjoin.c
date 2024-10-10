/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:48:19 by jalves-v          #+#    #+#             */
/*   Updated: 2024/10/04 19:19:48 by jalves-v         ###   ########.fr       */
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
