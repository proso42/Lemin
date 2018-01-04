/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:13:36 by proso             #+#    #+#             */
/*   Updated: 2018/01/03 22:48:49 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	**ft_new_array(int nb)
{
	char	**array;
	int		i;

	if (nb <= 0)
		return (NULL);
	if (!(array = (char**)malloc(sizeof(char*) * (nb + 1))))
	{
		ft_putstr_color("Fail to allocate memory with malloc function\n",
																		C_RED);
		exit(-1);
	}
	i = 0;
	while (i < nb + 1)
	{
		array[i] = ft_strnew(1024);
		i++;
	}
	array[i] = NULL;
	return (array);
}
