/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 00:12:34 by proso             #+#    #+#             */
/*   Updated: 2018/01/03 22:49:29 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	**ft_set_array(int nb, ...)
{
	va_list	ap;
	int		i;
	char	*str;
	char	**array;

	i = 0;
	if (nb <= 0)
		return (NULL);
	if (!(array = (char**)malloc(sizeof(char*) * (nb + 1))))
		exit(-1);
	va_start(ap, nb);
	while (nb > 0)
	{
		str = va_arg(ap, char *);
		array[i] = ft_strdup(str);
		i++;
		nb--;
	}
	va_end(ap);
	array[i] = NULL;
	return (array);
}
