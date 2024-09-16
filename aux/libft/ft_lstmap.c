/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:00:41 by jalves-v          #+#    #+#             */
/*   Updated: 2024/04/19 21:08:12 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;
	void	*temp;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		temp = f(lst->content);
		node = ft_lstnew(temp);
		if (!node)
		{
			del(temp);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}

// void	*f(unsigned long int content)
// {
// 	return ((void *)(content + 1));
// }

// void	del(void *content)
// {
// 	(void)content;
// 	return ;
// }

// #include <stdint.h>

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*temp;
// 	int		i;

// 	lst = NULL;
// 	i = 0;
// 	while (i < 5)
// 	{

// 		ft_lstadd_back(&lst, ft_lstnew((void *)(intptr_t)i));
// 		i++;
// 	}
// 	temp = lst;
// 	i = 0;
// 	while (temp != NULL)
// 	{
// 		printf("Before: %lu\n", (unsigned long int)temp->content);
// 		temp = temp->next;
// 		i++;
// 	}
// 	t_list	*new_lst;
// 	new_lst = ft_lstmap(lst, (void *) f, del);
// 	while (new_lst != NULL)
// 	{
// 		printf("After: %lu\n", (unsigned long int)new_lst->content);
// 			new_lst = new_lst->next;
// 		i++;
// 	}
// 	return (0);
// }