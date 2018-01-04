/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 23:38:18 by proso             #+#    #+#             */
/*   Updated: 2017/11/16 01:48:28 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char		*ft_strjoin_var(int nb, ...)
{
	va_list	ap;
	char	*join;
	int		size;
	int		i;

	if (nb <= 0)
		return (NULL);
	i = nb;
	size = 0;
	va_start(ap, nb);
	while (i > 0)
	{
		size += ft_strlen(va_arg(ap, char*));
		i--;
	}
	va_end(ap);
	va_start(ap, nb);
	join = ft_strnew(size);
	while (nb > 0)
	{
		ft_strcat(join, va_arg(ap, char*));
		nb--;
	}
	va_end(ap);
	return (join);
}
