/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:51:24 by proso             #+#    #+#             */
/*   Updated: 2018/01/04 20:27:42 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/lemin.h"

static int	get_nb_ant(t_data *info)
{
	long	nb;

	get_next_line(0, &info->line);
	nb = 0;
	while ((info->line)[nb])
	{
		if (!ft_isdigit(info->line[nb]))
			return (0);
		nb++;
	}
	nb = ft_atol(info->line);
	if (nb > 2147483647)
		return (0);
	info->ants = nb;
	ft_strdel(&info->line);
	return (1);
}

int			get_entry(t_data *info)
{
	if (!get_nb_ant(info))
		return(print_error(info, ERR_NB_ANT));
	if (!get_rooms(info))
		return (print_error(info, ERR_ROOM));
	return (1);
}
