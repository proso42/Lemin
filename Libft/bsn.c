/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsn.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 23:49:31 by proso             #+#    #+#             */
/*   Updated: 2018/01/16 23:50:30 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	bsn(int nb)
{
	while (nb > 0)
	{
		write(1, "\n", 1);
		nb--;
	}
}
