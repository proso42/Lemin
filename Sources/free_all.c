/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:08:59 by proso             #+#    #+#             */
/*   Updated: 2018/01/24 00:59:03 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/lemin.h"

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

static void	free_rooms(t_data *info)
{
	t_list	*current;
	t_list	*prev;

	current = info->room_list;
	prev = NULL;
	while (current)
	{
		ft_strdel(&((t_room*)current->data)->name);
		free_tubes(((t_room*)current->data)->tubes);
		free(current->data);
		prev = current;
		current = current->next;
		free(prev);
	}
}

static void	free_ants(t_data *info)
{
	t_list	*current;
	t_list	*prev;

	current = info->ant_list;
	prev = NULL;
	while (current)
	{
		prev = current;
		free(current->data);
		current = current->next;
		free(prev);
	}
}

void		free_all(t_data *info)
{
	free_rooms(info);
	free_ants(info);
	ft_remove_list(&info->way_list);
	ft_remove_list(&info->data_list);
	ft_strdel(&info->line);
}
