/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:29:48 by jalves-v          #+#    #+#             */
/*   Updated: 2024/04/17 15:23:14 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

// int	main(void)
// {
// 	char test1[] = "hello";
// 	char test2[] = "world";
// 	char test3[] = "!";

// 	t_list *head = ft_lstnew(test3);
// 	ft_lstadd_front(&head, ft_lstnew(test2));
// 	ft_lstadd_front(&head, ft_lstnew(test1));
// 	printf("%s\n", (char *)ft_lstlast(head)->content);
// 	return (0);
// }
