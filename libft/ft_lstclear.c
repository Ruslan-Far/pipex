/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:25:29 by ljaehaer          #+#    #+#             */
/*   Updated: 2021/10/11 22:36:01 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*t;

	if (!lst || !*lst || !del)
		return ;
	while ((*lst)->next)
	{
		t = *lst;
		*lst = (*lst)->next;
		del(t->content);
		free(t);
	}
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
}
