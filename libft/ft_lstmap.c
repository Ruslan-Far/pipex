/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:41:46 by ljaehaer          #+#    #+#             */
/*   Updated: 2021/11/12 15:26:56 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*delete_lst(t_list *start_new_lst, void (*del)(void *))
{
	ft_lstclear(&start_new_lst, del);
	return (start_new_lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*start_new_lst;

	if (!lst || !f)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	start_new_lst = NULL;
	if (!new_lst)
		return (delete_lst(start_new_lst, del));
	start_new_lst = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_lst->next = ft_lstnew(f(lst->content));
		if (!new_lst)
			return (delete_lst(start_new_lst, del));
		lst = lst->next;
		new_lst = new_lst->next;
	}
	return (start_new_lst);
}
