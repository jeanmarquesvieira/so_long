/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:48:39 by jalves-v          #+#    #+#             */
/*   Updated: 2024/04/18 17:25:13 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > start)
		end--;
	trimmed = malloc((sizeof(char) * (end - start) + 1));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, &s1[start], end - start + 1);
	return (trimmed);
}

// int	main(void)
// {
// 	char	*s1 = "*/D2klorem ipsum*/D2k";
// 	char	*set = "*/D2k";
// 	char	*s2 = "lorem-ipsum-lorem";
// 	char	*set2 = "lorem";
// 	char	*trimmed;
// 	char	*trimmed2;

// 	trimmed = ft_strtrim(s1, set);
// 	trimmed2 = ft_strtrim(s2, set2);
// 	printf("%s\n", trimmed);
// 	printf("%s\n", trimmed2);
// 	return (0);
// }
