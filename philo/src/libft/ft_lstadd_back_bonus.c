/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:00:58 by nlaporte          #+#    #+#             */
/*   Updated: 2024/11/12 16:49:13 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *neww)
{
	if (lst == NULL || neww == NULL)
		return ;
	else if (*lst == NULL)
	{
		*lst = neww;
		return ;
	}
	else if ((*lst)->next != NULL)
		return (ft_lstadd_back(&(*lst)->next, neww));
	(*lst)->next = neww;
	neww->prev = (*lst);
}
