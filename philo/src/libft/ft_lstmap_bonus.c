/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:20:12 by nlaporte          #+#    #+#             */
/*   Updated: 2024/11/12 16:49:13 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_abort(t_list *lst, void *last, void (*del)(void *))
{
	ft_lstclear(&lst, del);
	del(last);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_l;
	t_list	*new_n;
	void	*tmp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_l = NULL;
	while (lst != NULL)
	{
		tmp = f(lst->content);
		if (tmp == NULL)
		{
			ft_lstclear(&new_l, del);
			return (NULL);
		}
		new_n = ft_lstnew(tmp);
		if (new_n == NULL)
		{
			ft_abort(new_l, tmp, del);
			return (NULL);
		}
		ft_lstadd_back(&new_l, new_n);
		lst = lst->next;
	}
	return (new_l);
}
