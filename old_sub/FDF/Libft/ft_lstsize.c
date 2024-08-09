/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:59:26 by sehwjang          #+#    #+#             */
/*   Updated: 2023/10/28 22:15:06 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		cnt;

	if (lst == NULL)
		return (0);
	cnt = 0;
	temp = lst;
	while (temp)
	{
		temp = temp -> next;
		cnt++;
	}
	return (cnt);
}
