/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_anthill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 23:59:23 by proso             #+#    #+#             */
/*   Updated: 2018/01/21 01:43:05 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/visu.h"

static void	draw_tubes(t_visu *hex, t_room *room)
{
	int	x;
	int	y;
	int	color;
	t_list	*current;

	x = room->x;
	y = room->y;
	current = room->tubes;
	color = COLOR_W;
	while (current)
	{
		while (x != ((t_room*)current->data)->x)
		{
			mlx_pixel_put(hex->mlx, hex->win, x, y, color);
			(x < ((t_room*)current->data)->x) ? x++ : x--;
		}
		while (y != ((t_room*)current->data)->y)
		{
			mlx_pixel_put(hex->mlx, hex->win, x, y, color);
			(y < ((t_room*)current->data)->y) ? y++ : y--;
		}
		current = current->next;
	}
}

static void	draw_room(t_visu *hex, t_room *room)
{
	int		x;
	int		y;
	int		color;

	ft_init(0, 2, &x, &y);
	color = COLOR_W;
	if (room->type == END_ROOM)
		color = COLOR_R;
	else if (room->type == START_ROOM)
		color = COLOR_G;
	while (x < 10)
		mlx_pixel_put(hex->mlx, hex->win, room->x + x++, room->y + y, color);
	while (y < 10)
		mlx_pixel_put(hex->mlx, hex->win, room->x + x, room->y + y++, color);
	while (x > 0)
		mlx_pixel_put(hex->mlx, hex->win, room->x + x--, room->y + y, color);
	while (y > 0)
		mlx_pixel_put(hex->mlx, hex->win, room->x + x, room->y + y--, color);
}

void	draw_anthill(t_visu *hex)
{
	t_list	*current;

	current = hex->anthill;
	while (current)
	{
		draw_room(hex, (t_room*)current->data);
		draw_tubes(hex, (t_room*)current->data);
		current = current->next;
	}
}
