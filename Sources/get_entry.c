/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:51:24 by proso             #+#    #+#             */
/*   Updated: 2018/01/20 03:35:40 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/lemin.h"

static int	same_name(t_data *info)
{
	t_list	*current;
	t_list	*current2;
	char	*name;

	current = info->room_list;
	while (current)
	{
		name = ((t_room*)current->data)->name;
		current2 = current;
		while (current2)
		{
			if (!ft_strcmp(name, ((t_room*)current2->data)->name) &&
															current != current2)
				return (1);
			current2 = current2->next;
		}
		current = current->next;
	}
	return (0);
}

static int	same_coord(t_data *info)
{
	t_list	*current;
	t_list	*current2;
	int		x;
	int		y;

	current = info->room_list;
	while (current)
	{
		x = ((t_room*)current->data)->x;
		y = ((t_room*)current->data)->y;
		current2 = current;
		while (current2)
		{
			if (x == ((t_room*)current2->data)->x && y ==
							((t_room*)current2->data)->y && current != current2)
				return (1);
			current2 = current2->next;
		}
		current = current->next;
	}
	return (0);
}

static int	check_error(t_data *info)
{
	if (!info->room_list)
		return (ERR_NO_ROOM);
	else if (!info->start_ok)
		return (ERR_START);
	else if (!info->end_ok)
		return (ERR_END);
	else if (same_coord(info))
		return (ERR_COORD);
	else if (same_name(info))
		return (ERR_NAME);
	return (0);
}

static int	get_nb_ant(t_data *info)
{
	long	nb;

	ft_read_entry(&info->line);
	if (!info->line)
		return (0);
	ft_push_back(&info->data_list, ft_strdup(info->line));
	nb = 0;
	if (!ft_is_number(info->line))
		return (0);
	nb = ft_atol(info->line);
	if (nb > 2147483647 || ft_strlen(info->line) > 11 || nb <= 0)
		return (0);
	info->ants = nb;
	ft_strdel(&info->line);
	return (1);
}

int			get_entry(t_data *info)
{
	if (!get_nb_ant(info))
		return (print_error(info, ERR_NB_ANT));
	if (!get_rooms(info))
		return (print_error(info, ERR_ROOM));
	if (!get_tubes(info))
		return (print_error(info, ERR_TUBE));
	if ((info->error = check_error(info)))
		return (print_error(info, info->error));
	return (1);
}
