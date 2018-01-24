/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_better_way.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 01:05:40 by proso             #+#    #+#             */
/*   Updated: 2018/01/24 02:41:00 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/lemin.h"

static void	restart_forbidden_rooms(t_data *info)
{
	t_list	*current;

	current = info->room_list;
	while (current)
	{
		if (((t_room*)current->data)->type == START_ROOM)
			((t_room*)current->data)->forbidden = 1;
		else
			((t_room*)current->data)->forbidden = 0;
		current = current->next;
	}
}

void		find_better_way(t_data *info)
{
	t_list	*current;

	ft_remove_list(&info->way_list);
	current = info->room_list;
	while (current)
	{
		restart_forbidden_rooms(info);
		((t_room*)current->data)->forbidden = 1;
		if (find_way(info) && (ft_list_size(info->way_list) <
												ft_list_size(info->better_way)))
		{
			ft_remove_list(&info->better_way);
			info->better_way = ft_dup_list(info->way_list);
		}
		((t_room*)current->data)->forbidden = 0;
		ft_remove_list(&info->way_list);
		current = current->next;
	}
	info->way_list = ft_dup_list(info->better_way);
	ft_remove_list(&info->better_way);
}
