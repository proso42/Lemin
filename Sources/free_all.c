/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:08:59 by proso             #+#    #+#             */
/*   Updated: 2018/01/17 01:13:10 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/lemin.h"

void	free_all(t_data *info)
{
	t_list	*current;
	t_list	*prev;

	current = info->room_list;
	prev = NULL;
	while (current)
	{
		ft_strdel(&((t_room*)current->data)->name);
		prev = current;
		current = current->next;
		free(prev);
	}
	ft_strdel(&info->line);
}
