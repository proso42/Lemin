/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <proso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 02:30:23 by proso             #+#    #+#             */
/*   Updated: 2017/12/14 02:32:31 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(char const *str)
{
	long i;
	long sign;
	long nb;

	sign = 1;
	i = 0;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == 43)
		i++;
	else if (str[i] == 45)
	{
		i++;
		sign = -1;
	}
	while (str[i] >= 48 && str[i] <= 57)
		nb = (nb * 10) + (str[i++] - 48);
	nb *= sign;
	return (nb);
}
