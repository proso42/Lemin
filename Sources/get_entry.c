/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_entry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:51:24 by proso             #+#    #+#             */
/*   Updated: 2018/01/17 00:50:15 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/lemin.h"

static int	get_nb_ant(t_data *info)
{
	long	nb;

	ft_read_entry(&info->line);
	nb = 0;
	while ((info->line)[nb] != '\0')
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
	ft_printf("{bold}{green}Les fourmis :{res}\n");
	if (!get_nb_ant(info))
		return (print_error(info, ERR_NB_ANT));
	ft_printf("{bold}{green}Les salles :{res}\n");
	if (!get_rooms(info))
		return (print_error(info, ERR_ROOM));
	ft_printf("{bold}{green}Les tubes :{res}\n");
	if (!get_tubes(info))
		return (print_error(info, ERR_TUBE));
	return (1);
}
