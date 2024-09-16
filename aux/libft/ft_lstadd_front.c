/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:30:26 by jalves-v          #+#    #+#             */
/*   Updated: 2024/04/17 12:00:03 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	char	s1[] = "hello";
// 	char	s2[] = "world";
// 	t_list	*head = NULL;
// 	head = ft_lstnew(s1);
// 	ft_lstadd_front(&head, ft_lstnew(s2));
// 	printf("content: %s\n next: %s\n",
//	(char *)head->content, (char *)head->next->content);
// 	return (0);
// }
