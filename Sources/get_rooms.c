/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 19:42:14 by proso             #+#    #+#             */
/*   Updated: 2018/01/04 20:30:16 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/lemin.h"

static int	get_name_room(t_data *info, t_room *room)
{
	(void)info;
	(void)room;
	return (1);
}

static int	get_coord_room(t_data *info, t_room *room, char c)
{
	(void)info;
	(void)room;
	(void)c;
	return (1);
}

static int	create_std_room(t_data *info)
{
	t_room	*room;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		print_error(info, ERR_MALLOC);
	if (!get_name_room(info, room) || !get_coord_room(info, room, 'x') ||
		!get_coord_room(info, room, 'y'))
		return (0);
	return (1);
	room->type = -1;
	room->empty = 1;
	room->tubes = NULL;
}

static int	create_start_room(t_data *info)
{
	t_room	*room;

	if (info->start_ok)
		return (0);
	ft_strdel(&info->line);
	get_next_line(0, &info->line);
	if (!(room = (t_room*)malloc(sizeof(t_room))))
		print_error(info, ERR_MALLOC);
	if (!get_name_room(info, room) || !get_coord_room(info, room, 'x') ||
		!get_coord_room(info, room, 'y'))
		return (0);
	room->type = 1;
	info->start_ok = 1;
	room->empty = 1;
	room->tubes = NULL;
	return (1);
}

static int	create_end_room(t_data *info)
{
	t_room	*room;

	if (info->end_ok)
		return (0);
	ft_strdel(&info->line);
	get_next_line(0, &info->line);
	if (!(room = (t_room*)malloc(sizeof(t_room))))
		print_error(info, ERR_MALLOC);
	if (!get_name_room(info, room) || !get_coord_room(info, room, 'x') ||
		!get_coord_room(info, room, 'y'))
		return (0);
	room->type = 0;
	info->end_ok = 1;
	room->empty = 1;
	room->tubes = NULL;
	return (1);
}

int			get_rooms(t_data *info)
{
	int		err;

	while (get_next_line(0, &info->line))
	{
		if (ft_strlen(info->line) >= 3 && ft_isdigit(info->line[0]) &&
							info->line[1] == '-' && ft_isdigit(info->line[2]))
			break ;
		else if (!ft_strcmp("##start", info->line))
			err = create_start_room(info);
		else if (!ft_strcmp("##end", info->line))
			err = create_end_room(info);
		else if (info->line[0] != 'L' && info->line[0] != '#')
			err = create_std_room(info);
		ft_strdel(&info->line);
	}
	if (info->line)
		ft_strdel(&info->line);
	return (1);
}
