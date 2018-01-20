/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:02:31 by proso             #+#    #+#             */
/*   Updated: 2018/01/20 03:51:09 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/lemin.h"

static void	init(t_data *info)
{
	info->room_list = NULL;
	info->checked_room_list = NULL;
	info->way_list = NULL;
	info->way = NULL;
	info->ant_list = NULL;
	info->data_list = NULL;
	info->line = NULL;
	ft_init(0, 4, &info->start_ok, &info->end_ok, &info->rooms_ok, &info->ants);
}

int			main(void)
{
	t_data	info;

	init(&info);
	if (!(get_entry(&info)))
		return (0);
	gen_ants(&info);
	if (!(find_way(&info)))
		return (print_error(&info, ERR_WAY));
	ft_print_list(info.data_list);
	bsn(1);
	move_ants(&info);
	free_all(&info);
	return (0);
}
