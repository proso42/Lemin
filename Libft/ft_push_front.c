/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 13:03:42 by proso             #+#    #+#             */
/*   Updated: 2018/01/20 01:09:59 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

t_list	*ft_push_front(t_list **begin_list, void *item)
{
	t_list	*elem;

	if (!(elem = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	elem->data = item;
	elem->size = 0;
	if (!*begin_list)
		elem->next = NULL;
	else
		elem->next = *begin_list;
	elem->prev = NULL;
	if (elem->next)
		elem->next->prev = elem;
	*begin_list = elem;
	return (elem);
}
