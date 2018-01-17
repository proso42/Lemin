/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:02:31 by proso             #+#    #+#             */
/*   Updated: 2018/01/17 01:28:56 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/lemin.h"

static void	print_anthill(t_data *info)
{
	t_list	*current;
	t_list	*p;

	current = info->room_list;
	ft_printf("Nombre de fourmis : %d\n", info->ants);
	while (current)
	{
		ft_printf("Salle : %s - Connexion(s) avec :\n",
												((t_room*)current->data)->name);
		p = ((t_room*)current->data)->tubes;
		if (!p)
			bsn(1);
		while (p)
		{
			ft_printf("\t%s\n", ((t_room*)p->data)->name);
			p = p->next;
		}
		current = current->next;
	}
}

static void	init(t_data *info)
{
	info->room_list = NULL;
	info->line = NULL;
	ft_init(0, 4, &info->start_ok, &info->end_ok, &info->rooms_ok, &info->ants);
}

int			main(void)
{
	t_data	info;

	init(&info);
	if (!(get_entry(&info)))
		return (0);
	print_anthill(&info);
	return (0);
}
