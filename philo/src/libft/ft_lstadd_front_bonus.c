/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaporte <nlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:04:47 by nlaporte          #+#    #+#             */
/*   Updated: 2024/11/12 16:49:13 by nlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *neww)
{
	if (lst == NULL || neww == NULL)
		return ;
	(*lst)->prev = neww;
	neww->next = *lst;
	*lst = neww;
}
