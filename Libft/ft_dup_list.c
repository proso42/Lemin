/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 18:15:31 by proso             #+#    #+#             */
/*   Updated: 2018/01/24 02:33:38 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

t_list	*ft_dup_list(t_list *begin_list)
{
	t_list	*new_list;
	t_list	*current;

	if (!begin_list)
		return (NULL);
	new_list = NULL;
	current = begin_list;
	while (current)
	{
		ft_push_back(&new_list, ft_strdup(current->data));
		current = current->next;
	}
	return (new_list);
}
