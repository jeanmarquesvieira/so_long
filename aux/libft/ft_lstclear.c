/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:50:18 by jalves-v          #+#    #+#             */
/*   Updated: 2024/04/20 13:36:27 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	temp = *lst;
	while (temp)
	{
		temp = temp->next;
		del((*lst)->content);
		free((*lst));
		*lst = temp;
	}
	*lst = NULL;
}

// void	delete(void *test)
// {
// 	printf("del func: %s\n", (char *)test);
// }

// int	main(void)
// {
// 	char test1[] = "hello";
// 	char test2[] = "world";
// 	char test3[] = "!";

// 	t_list *head = ft_lstnew(test3);
// 	ft_lstadd_front(&head, ft_lstnew(test2));
// 	ft_lstadd_front(&head, ft_lstnew(test1));
// 	ft_lstclear(&head, delete())
// 	return (0);
// }