/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-v <jalves-v@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:47:36 by jalves-v          #+#    #+#             */
/*   Updated: 2024/04/17 11:25:47 by jalves-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lstnew;

	lstnew = malloc(sizeof(t_list));
	if (!lstnew)
		return (NULL);
	lstnew->content = content;
	lstnew->next = NULL;
	return (lstnew);
}

// int	main(void)
// {
// 	char s1[] = "Hello";
// 	t_list *head;
// 	head = ft_lstnew(s1);
// 	printf("%s\n", (char *)head->content);
// 	return (0);
// }
