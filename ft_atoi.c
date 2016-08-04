/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hczuba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:33:24 by hczuba            #+#    #+#             */
/*   Updated: 2016/07/19 23:25:45 by hczuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_atoi(char *str)
{
	int nb;
	int i;
	int sign;

	nb = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (!(str[i] <= 57 && str[i] >= 48))
			return (nb * sign);
		if (i > 0)
			nb *= 10;
		nb += (str[i] - 48);
		i++;
	}
	return (nb * sign);
}
