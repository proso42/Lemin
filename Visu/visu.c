/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 22:52:54 by proso             #+#    #+#             */
/*   Updated: 2018/01/21 01:13:08 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/visu.h"

static void	init(t_visu *hex)
{
	hex->line = NULL;
	hex->anthill = NULL;
	hex->way = NULL;
	hex->mlx = mlx_init();
	hex->win = mlx_new_window(hex->mlx, 1500, 1000, "Visualisateur");
}

int		main(void)
{
	t_visu	hex;

	init(&hex);
	get_anthill(&hex);
	draw_anthill(&hex);
	mlx_loop(hex.mlx);
	free_all(&hex);
	return (0);
}
