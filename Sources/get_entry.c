/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:51:24 by proso             #+#    #+#             */
/*   Updated: 2018/01/19 02:43:28 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/lemin.h"

static int	check_error(t_data *info)
{
	if (!info->room_list)
		return (ERR_NO_ROOM);
	else if (!info->start_ok)
		return (ERR_START);
	else if (!info->end_ok)
		return (ERR_END);
	return (0);
}

static int	get_nb_ant(t_data *info)
{
	long	nb;

	ft_read_entry(&info->line);
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
	ft_printf("{bold}{green}Les fourmis :{res}\n");
	if (!get_nb_ant(info))
		return (print_error(info, ERR_NB_ANT));
	ft_printf("{bold}{green}Les salles :{res}\n");
	if (!get_rooms(info))
		return (print_error(info, ERR_ROOM));
	ft_printf("{bold}{green}Les tubes :{res}\n");
	if (!get_tubes(info))
		return (print_error(info, ERR_TUBE));
	if ((info->error = check_error(info)))
		return (print_error(info, info->error));
	
	return (1);
}
