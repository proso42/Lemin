/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 22:50:37 by proso             #+#    #+#             */
/*   Updated: 2018/01/21 01:32:24 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H

# define VISU_H

# include "libft.h"
# include "mlx.h"

# define START_ROOM	60
# define END_ROOM	61
# define STD_ROOM	62
# define ERR_MALLOC	63
# define COLOR_W	0xFFFFFF
# define COLOR_G	0x19FF7B
# define COLOR_R	0xCC1844

typedef	struct	s_room
{
	int			x;
	int			y;
	int			type;
	char		*name;
	t_list		*tubes;
}				t_room;

typedef struct	s_visu
{
	char		*line;
	void		*mlx;
	void		*win;
	t_list		*anthill;
	t_list		*way;
}				t_visu;

int				print_error(t_visu *hex, int err);
void			free_all(t_visu *hex);
void			get_anthill(t_visu *hex);
void			draw_anthill(t_visu *hex);

#endif
