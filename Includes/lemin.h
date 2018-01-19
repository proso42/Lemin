/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:09:44 by proso             #+#    #+#             */
/*   Updated: 2018/01/19 02:42:15 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H

# define LEMIN_H

# define ERR_NB_ANT 	50
# define ERR_ROOM		51
# define ERR_TUBE		52
# define ERR_MALLOC		53
# define ERR_NO_ROOM	54
# define ERR_END		55
# define ERR_START		56
# define ERR_WAY		57
# define STD_ROOM		60
# define START_ROOM		61
# define END_ROOM		62

# include "libft.h"

typedef struct	s_room
{
	int			x;
	int			y;
	int			type;
	int			nb;
	char		*name;
	t_list		*tubes;
}				t_room;

typedef struct	s_data
{
	t_list		*room_list;
	char		*line;
	int			ants;
	int			start_ok;
	int			end_ok;
	int			rooms_ok;
	int			error;
	t_room		*way;
	t_list		*way_list;
	t_list		*checked_room_list;
}				t_data;

void			free_all(t_data *info);
int				print_error(t_data *info, int err);
int				get_entry(t_data *info);
int				get_rooms(t_data *info);
int				get_tubes(t_data *info);
int				find_way(t_data *info);
void			move_ants(t_data *info);

#endif
