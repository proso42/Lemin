/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 02:39:00 by proso             #+#    #+#             */
/*   Updated: 2018/01/20 23:20:04 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/lemin.h"

void			gen_ants(t_data *info)
{
	int		i;
	t_ant	*new_ant;

	i = 1;
	while (i <= info->ants)
	{
		if (!(new_ant = (t_ant*)malloc(sizeof(t_ant))))
			print_error(info, ERR_MALLOC);
		new_ant->id = i;
		new_ant->pos = (t_room*)info->room_list->data;
		ft_push_back(&info->ant_list, new_ant);
		i++;
	}
}

static t_room	*find_next_room(t_data *info, char *name)
{
	t_list	*current;

	current = info->room_list;
	while (current)
	{
		if (!ft_strcmp(name, ((t_room*)current->data)->name))
			return (current->data);
		current = current->next;
	}
	return (NULL);
}

static t_room	*get_next_room(t_data *info, char *name)
{
	t_list	*current;

	current = info->way_list;
	while (current)
	{
		if (!ft_strcmp(name, current->data))
			return (find_next_room(info, current->next->data));
		current = current->next;
	}
	return (NULL);
}

static int		travel(t_data *info, t_list *current)
{
	t_room	*next_room;

	if (!current)
		return (0);
	if (((t_ant*)current->data)->pos->type == END_ROOM)
	{
		((t_ant*)current->data)->pos->nb++;
		return (1);
	}
	next_room = get_next_room(info, ((t_ant*)current->data)->pos->name);
	if (next_room->nb && next_room->type != END_ROOM)
		return (0);
	((t_ant*)current->data)->pos->nb = 0;
	((t_ant*)current->data)->pos = next_room;
	((t_ant*)current->data)->pos->nb = 1;
	ft_printf("L%d-%s ", ((t_ant*)current->data)->id,
											((t_ant*)current->data)->pos->name);
	return (1);
}

void			move_ants(t_data *info)
{
	t_list	*current;
	int		i;

	i = 0;
	ft_push_front(&info->way_list,
							ft_strdup(((t_room*)info->room_list->data)->name));
	while (info->way->nb < info->ants)
	{
		if (i)
			bsn(1);
		i++;
		current = info->ant_list;
		while (travel(info, current))
			current = current->next;
	}
}
