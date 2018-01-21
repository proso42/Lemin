/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 23:17:40 by proso             #+#    #+#             */
/*   Updated: 2018/01/21 01:41:27 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/visu.h"

static int	create_room(t_visu *hex, int type)
{
	t_room	*new_room;
	char	**tab;

	if (!(new_room = (t_room*)malloc(sizeof(t_room))))
		print_error(hex, ERR_MALLOC);
	tab = ft_strsplit(hex->line, ' ');
	new_room->name = ft_strdup(tab[0]);
	new_room->x = (ft_atoi(tab[1]) * 30) + 500;
	new_room->y = (ft_atoi(tab[2]) * 30) + 300;
	new_room->type = type;
	new_room->tubes = NULL;
	ft_push_back(&hex->anthill, new_room);
	ft_del_tab(tab);
	return (STD_ROOM);
}

static t_room	*find_room(t_list *anthill, char *name)
{
	t_list	*current;

	current = anthill;
	while (current)
	{
		if (!ft_strcmp(name, ((t_room*)current->data)->name))
			return (current->data);
		current = current->next;
	}
	return (NULL);
}

static int		join_rooms(t_visu *hex, char *name1, char *name2)
{
	t_room	*r1;
	t_room	*r2;

	if (!ft_strcmp(name1, name2))
		return (0);
	if (!(r1 = find_room(hex->anthill, name1)))
		return (0);
	if (!(r2 = find_room(hex->anthill, name2)))
		return (0);
	ft_push_back(&r1->tubes, r2);
	ft_push_back(&r2->tubes, r1);
	return (1);
}

static void		get_tubes(t_visu *hex)
{
	char	**tab;

	if (!hex->line || !hex->line[0] || hex->line[0] == '\n')
		ft_read_entry(&hex->line);
	while (hex->line && hex->line[0])
	{
		tab = ft_strsplit(hex->line, '-');
		join_rooms(hex, tab[0], tab[1]);
		ft_del_tab(tab);
		ft_strdel(&hex->line);
		ft_read_entry(&hex->line);
	}
}

void			get_anthill(t_visu *hex)
{
	int	type;

	type = STD_ROOM;
	ft_read_entry(&hex->line);
	while (1)
	{
		ft_strdel(&hex->line);
		ft_read_entry(&hex->line);
		if (!hex->line || !hex->line[0] || hex->line[0] == '\n' ||
					(ft_strchr(hex->line, '-') && !ft_strchr(hex->line, ' ')))
		{
			get_tubes(hex);
			return ;
		}
		else if (!ft_strcmp("##start", hex->line))
			type = START_ROOM;
		else if (!ft_strcmp("##end", hex->line))
			type = END_ROOM;
		else if (hex->line[0] == '#')
			continue ;
		else
			type = create_room(hex, type);
	}
}
