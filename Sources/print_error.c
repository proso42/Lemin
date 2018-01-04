/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:06:11 by proso             #+#    #+#             */
/*   Updated: 2018/01/04 20:02:56 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/lemin.h"

int		print_error(t_data *info, int err)
{
	free_all(info);
	if (err == ERR_NB_ANT)
		ft_dprintf(2, "{bold}{red}Invalid number of ants !{res}\n");
	else if (err == ERR_ROOM)
		ft_dprintf(2, "{bold}{red}Invalid pathern of room !{res}\n");
	else if (err == ERR_TUBE)
		ft_dprintf(2, "{bold}{red}Invalid pathern of tube !{res}\n");
	else if (err == ERR_MALLOC)
	{
		ft_dprintf(2, "{bold}{red}Fail of malloc function !{res}\n");
		exit(-1);
	}
	return (0);
}
