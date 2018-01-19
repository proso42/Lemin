/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:08:59 by proso             #+#    #+#             */
/*   Updated: 2018/01/19 01:26:26 by proso            ###   ########.fr       */
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
		free(current->data);
		prev = current;
		current = current->next;
		free(prev);
	}
	current = info->checked_room_list;
	prev = NULL;
	while (current)
	{
		prev = current;
		current = current->next;
		free(prev);
	}
	ft_remove_list(&info->way_list);
	ft_strdel(&info->line);
}
