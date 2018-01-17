/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_entry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 00:29:17 by proso             #+#    #+#             */
/*   Updated: 2018/01/17 01:09:55 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	ft_read_entry(char **line)
{
	char	buff[10];
	char	*tmp;
	int		ret;

	tmp = NULL;
	while ((ret = read(0, buff, 1)))
	{
		if (buff[0] == '\n')
			break ;
		tmp = ft_strjoinfree(tmp, buff, 1);
	}
	if (tmp == NULL)
	{
		*line = NULL;
		return ;
	}
	*line = ft_strdup(tmp);
	ft_strdel(&tmp);
}
