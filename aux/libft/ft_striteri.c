/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:48:17 by jalves-v          #+#    #+#             */
/*   Updated: 2024/04/18 13:10:06 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void	upper_or_lower(unsigned int i, char *c)
// {
// 	(void)i;
// 	if (*c >= 65 && *c <= 90)
// 		*c += 32;
// 	else if (*c >= 97 && *c <= 122)
// 		*c -= 32;
// }

// int	main(void)
// {
// 	char test[] = "*tHIS Is a tEst!-";
// 	printf("before: %s\n", test);
// 	ft_striteri(test, upper_or_lower);
// 	printf(" after: %s\n", test);
// 	return (0);
// }
