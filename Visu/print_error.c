/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 23:40:09 by proso             #+#    #+#             */
/*   Updated: 2018/01/21 01:33:06 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/visu.h"

static void	free_tubes(t_list *list)
{
	t_list	*current;
	t_list	*prev;

	current = list;
	prev = NULL;
	while (current)
	{
		prev = current;
		current = current->next;
		free(prev);
	}
}

void	free_all(t_visu *hex)
{
	t_list	*current;
	t_list	*prev;

	prev = NULL;
	current = hex->anthill;
	while (current)
	{
		prev = current;
		ft_strdel((char**)&(((t_room*)current->data)->name));
		free_tubes(((t_room*)current->data)->tubes);
		free(current->data);
		current = current->next;
		free(prev);
	}
	ft_strdel(&hex->line);
	ft_remove_list(&hex->way);
}

int			print_error(t_visu *hex, int err)
{
	free_all(hex);
	if (err == ERR_MALLOC)
	{
		ft_dprintf(2, "{bold}{red}Fail with malloc function !{res}\n");
		exit(-1);
	}
	return (0);
}
