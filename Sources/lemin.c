/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:02:31 by proso             #+#    #+#             */
/*   Updated: 2018/01/19 02:35:45 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/lemin.h"

/*static void	print_anthill(t_data *info)
{
	t_list	*current;
	t_list	*p;

	current = info->room_list;
	ft_printf("{bold}{cyan}Nombre de fourmis : [{red}%d{cyan}]{res}\n", info->ants);
	while (current)
	{
		ft_printf("{bold}Salle : {yellow}%s{white} - Connexion(s) avec :{res}\n",
												((t_room*)current->data)->name);
		p = ((t_room*)current->data)->tubes;
		if (!p)
			bsn(2);
		while (p)
		{
			ft_printf("\t{bold}{cyan}%s{res}\n", ((t_room*)p->data)->name);
			p = p->next;
		}
		current = current->next;
	}
}*/

static void	init(t_data *info)
{
	info->room_list = NULL;
	info->checked_room_list = NULL;
	info->way_list = NULL;
	info->way = NULL;
	info->line = NULL;
	ft_init(0, 4, &info->start_ok, &info->end_ok, &info->rooms_ok, &info->ants);
}

int			main(void)
{
	t_data	info;

	init(&info);
	if (!(get_entry(&info)))
		return (0);
//	print_anthill(&info);
	if (!(find_way(&info)))
		print_error(&info, ERR_WAY);
	else
		ft_print_list(info.way_list);
	return (0);
}
