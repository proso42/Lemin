/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tubes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 23:27:16 by proso             #+#    #+#             */
/*   Updated: 2018/01/24 02:45:11 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/lemin.h"

static t_room	*find_room(t_list *room_list, char *name)
{
	t_list	*current;

	current = room_list;
	while (current)
	{
		if (!ft_strcmp(name, ((t_room*)current->data)->name))
			return (current->data);
		current = current->next;
	}
	return (NULL);
}

static int		join_rooms(t_data *info, char *name1, char *name2)
{
	t_room	*r1;
	t_room	*r2;

	if (!ft_strcmp(name1, name2))
		return (0);
	if (!(r1 = find_room(info->room_list, name1)))
		return (0);
	if (!(r2 = find_room(info->room_list, name2)))
		return (0);
	ft_push_back(&r1->tubes, r2);
	ft_push_back(&r2->tubes, r1);
	return (1);
}

int				get_tubes(t_data *info)
{
	char	**tab;

	while (1)
	{
		if (!info->line)
			ft_read_entry(&info->line);
		if (!info->line)
			return (1);
		ft_push_back(&info->data_list, ft_strdup(info->line));
		if (info->line[0] != '#')
		{
			tab = ft_strsplit(info->line, '-');
			if (tab[2] || !(join_rooms(info, tab[0], tab[1])))
			{
				ft_del_tab(tab);
				return (0);
			}
			ft_del_tab(tab);
		}
		ft_strdel(&info->line);
	}
	return (1);
}
