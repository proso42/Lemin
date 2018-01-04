/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:09:44 by proso             #+#    #+#             */
/*   Updated: 2018/01/04 20:26:54 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H

# define LEMIN_H

# define ERR_NB_ANT 50
# define ERR_ROOM	51
# define ERR_TUBE	52
# define ERR_MALLOC	53

# include "libft.h"

typedef struct	s_room
{
	int			x;
	int			y;
	int			type;
	int			empty;
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
}				t_data;

void			free_all(t_data *info);
int				print_error(t_data *info, int err);
int				get_entry(t_data *info);
int				get_rooms(t_data *info);

#endif
