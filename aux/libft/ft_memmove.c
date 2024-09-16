/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:47:46 by jalves-v          #+#    #+#             */
/*   Updated: 2024/04/20 12:23:47 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (((unsigned char *)dst) < ((unsigned char *)src))
		return (ft_memcpy(dst, src, len));
	else
	{
		while (len-- >= 1)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	}
	return (dst);
}

// int	main(void)
// {
// 	int	arr[4] = {1, 2, 3, 4};
// 	int	arr2[4];
// 	int	i = 0;

// 	ft_memmove(arr2, arr, sizeof(arr));
// 	while (i < 4)
// 		printf("%d\n", arr2[i++]);
// 	return (0);
// }
