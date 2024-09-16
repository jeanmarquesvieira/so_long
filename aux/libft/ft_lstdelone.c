/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:17:59 by jalves-v          #+#    #+#             */
/*   Updated: 2024/04/20 10:33:08 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

// int	main(void)
// {
// 	t_list *head;
// 	char	test[] = "!";
// 	char	test2[] = "world";
// 	char	test3[] = "hello";

// 	head = ft_lstnew(test);
// 	ft_lstadd_front(&head, ft_lstnew(test2));
// 	ft_lstadd_front(&head, ft_lstnew(test3));
// 	ft_lstdelone(head, del);
// 	printf("%s\n", (char *)head->content);
// 	return (0);
// }
