/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 19:42:14 by proso             #+#    #+#             */
/*   Updated: 2018/01/17 18:02:14 by i                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/lemin.h"

static int	get_datas_room(t_data *info, t_room *room)
{
	char	**tab;

	tab = ft_strsplit(info->line, ' ');
	if (tab[0][0] == '#' || tab[0][0] == 'L' || !ft_is_number(tab[1]) ||
														!ft_is_number(tab[2]))
	{
		ft_del_tab(tab);
		return (0);
	}
	room->name = ft_strdup(tab[0]);
	room->x = ft_atoi(tab[1]);
	room->y = ft_atoi(tab[2]);
	ft_del_tab(tab);
	return (1);
}

static int	create_std_room(t_data *info)
{
	t_room	*room;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		print_error(info, ERR_MALLOC);
	if (!get_datas_room(info, room))
		return (0);
	room->type = STD_ROOM;
	room->empty = 1;
	room->tubes = NULL;
	ft_push_back(&info->room_list, room);
	return (1);
}

static int	create_start_room(t_data *info)
{
	t_room	*room;

	if (info->start_ok)
		return (0);
	ft_strdel(&info->line);
	ft_read_entry(&info->line);
	if (!info->line)
		return (0);
	if (!(room = (t_room*)malloc(sizeof(t_room))))
		print_error(info, ERR_MALLOC);
	if (!get_datas_room(info, room))
		return (0);
	room->type = START_ROOM;
	info->start_ok = 1;
	room->empty = 1;
	room->tubes = NULL;
	ft_push_back(&info->room_list, room);
	return (1);
}

static int	create_end_room(t_data *info)
{
	t_room	*room;

	if (info->end_ok)
		return (0);
	ft_strdel(&info->line);
	ft_read_entry(&info->line);
	if (!info->line)
		return (0);
	if (!(room = (t_room*)malloc(sizeof(t_room))))
		print_error(info, ERR_MALLOC);
	if (!get_datas_room(info, room))
		return (0);
	room->type = END_ROOM;
	info->end_ok = 1;
	room->empty = 1;
	room->tubes = NULL;
	ft_push_back(&info->room_list, room);
	return (1);
}

int			get_rooms(t_data *info)
{
	int		ret;

	while (1)
	{
		ft_read_entry(&info->line);
		if (!info->line)
			return (1);
		if (!ft_strchr(info->line, ' ') && (info->line)[0] != '#')
			return (1);
		else if (!ft_strcmp("##start", info->line))
			ret = create_start_room(info);
		else if (!ft_strcmp("##end", info->line))
			ret = create_end_room(info);
		else if (info->line[0] == '#')
			ret = 1;
		else
			ret = create_std_room(info);
		ft_strdel(&info->line);
		if (!ret)
			return (0);
	}
	if (info->line)
		ft_strdel(&info->line);
	return (1);
}
