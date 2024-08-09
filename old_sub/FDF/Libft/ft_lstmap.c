/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:56:46 by sehwjang          #+#    #+#             */
/*   Updated: 2023/11/03 16:32:16 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*head;
	t_list	*new;
	void	*new_content;

	head = NULL;
	temp = lst;
	while (temp)
	{
		new_content = f(temp -> content);
		new = ft_lstnew(new_content);
		if (new == NULL || new_content == NULL)
		{
			free(new);
			(*del)(new_content);
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, new);
		temp = temp -> next;
	}
	return (head);
}
