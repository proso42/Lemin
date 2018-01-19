/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 00:33:57 by proso             #+#    #+#             */
/*   Updated: 2018/01/19 02:37:42 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/lemin.h"

static t_room	*choice_room(t_data *info)
{
	t_list	*current;

	current = ((t_room*)info->way)->tubes;
	while (current)
	{
		if (ft_list_find(info->checked_room_list,
												((t_room*)current->data)->name))
			current = current->next;
		else
		{
			ft_push_back(&info->checked_room_list,
									ft_strdup(((t_room*)current->data)->name));
			return (current->data);
		}
	}
	return (NULL);
}

static int		go_room(t_data *info)
{
	t_room	*prev_way;

	prev_way = info->way;
	if (!(info->way = choice_room(info)))
		return (0);
	ft_push_back(&info->way_list, ft_strdup(((t_room*)info->way)->name));
	if (((t_room*)info->way)->type == END_ROOM)
		return (1);
	while (!go_room(info))
	{
		ft_clear_elem(&info->way_list, ft_list_last(info->way_list));
		info->way = prev_way;
		if (!(info->way = choice_room(info)))
			return (0);
		ft_push_back(&info->way_list, ft_strdup(((t_room*)info->way)->name));
		if (((t_room*)info->way)->type == END_ROOM)
			return (1);
	}
	return (1);
}

int				find_way(t_data *info)
{
	info->way = info->room_list->data;
	ft_push_back(&info->checked_room_list,
							ft_strdup(((t_room*)info->room_list->data)->name));
	if (!(go_room(info)))
		return (0);
	return (1);
}
