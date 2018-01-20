/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:06:11 by proso             #+#    #+#             */
/*   Updated: 2018/01/20 02:56:55 by proso            ###   ########.fr       */
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
	else if (err == ERR_END)
		ft_dprintf(2, "{bold}{red}Missing end room !{res}\n");
	else if (err == ERR_START)
		ft_dprintf(2, "{bold}{red}Missing start room !{res}\n");
	else if (err == ERR_NO_ROOM)
		ft_dprintf(2, "{bold}{red}Error : no room !{res}\n");
	else if (err == ERR_WAY)
		ft_dprintf(2, "{bold}{red}No way to escape !{res}\n");
	else if (err == ERR_COORD)
		ft_dprintf(2, "{bold}{red}Some rooms have the same position !{res}\n");
	else if (err == ERR_NAME)
		ft_dprintf(2, "{bold}{red}Some rooms have the same name !{res}\n");
	else if (err == ERR_MALLOC)
	{
		ft_dprintf(2, "{bold}{red}Fail of malloc function !{res}\n");
		exit(-1);
	}
	return (0);
}
