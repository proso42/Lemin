/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:02:31 by proso             #+#    #+#             */
/*   Updated: 2018/01/04 19:36:38 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/lemin.h"

static void	init(t_data *info)
{
	info->room_list = NULL;
	info->line = NULL;
	ft_init(0, 4, info->start_ok, info->end_ok, info->rooms_ok, info->ants);
}

int		main(void)
{
	t_data	info;

	init(&info);
	get_entry(&info);
	return (0);
}
