/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 23:19:40 by proso             #+#    #+#             */
/*   Updated: 2018/01/03 22:50:44 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

size_t	ft_strlcpy(char *dst, char const *src, size_t size)
{
	ft_strncpy(dst, src, size);
	dst[size] = '\0';
	return (ft_strlen(src));
}
