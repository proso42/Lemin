/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:20:25 by proso             #+#    #+#             */
/*   Updated: 2017/11/11 01:36:26 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	ft_del_tab(char **args)
{
	int		i;

	i = 0;
	if (args)
	{
		while ((args[i]))
		{
			ft_strdel(&(args[i]));
			i++;
		}
		free(args);
		args = NULL;
	}
}
