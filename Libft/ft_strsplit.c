/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:51:04 by proso             #+#    #+#             */
/*   Updated: 2017/12/14 03:28:07 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

static void	ft_fill_tab(char **tab, char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			while (*s != c && *s != '\0')
			{
				tab[i][j] = *s;
				j++;
				s++;
			}
			tab[i][j] = '\0';
			j = 0;
			i++;
		}
	}
}

static int	count_word(char const *s, char c)
{
	int		n;

	while (*s && *s == c)
		s++;
	n = 0;
	while (*s)
	{
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
		n++;
	}
	return (n);
}

static char	**ft_alloc(char const *s, char c)
{
	int		n;
	int		i;
	char	**tab;

	i = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (count_word(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			n = 0;
			while (*s && *s != c && n++ >= 0)
				s++;
			if (!(tab[i] = (char*)malloc(sizeof(char) * (n + 1))))
				return (NULL);
			i++;
		}
	}
	tab[i] = NULL;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (0);
	tab = ft_alloc(s, c);
	ft_fill_tab(tab, s, c);
	return (tab);
}
