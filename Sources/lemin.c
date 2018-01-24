/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:02:31 by proso             #+#    #+#             */
/*   Updated: 2018/01/24 02:38:53 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/lemin.h"

static void	init(t_data *info)
{
	info->room_list = NULL;
	info->way_list = NULL;
	info->better_way = NULL;
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
	info.end = info.way;
	info.better_way = ft_dup_list(info.way_list);
	find_better_way(&info);
	ft_print_list(info.data_list);
	bsn(1);
	move_ants(&info);
	free_all(&info);
	return (0);
}
