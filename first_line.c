/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hczuba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 15:31:30 by hczuba            #+#    #+#             */
/*   Updated: 2016/08/03 15:32:56 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*substr(int start, int end, char *str)
{
	char	*sub;
	int		i;

	sub = malloc(sizeof(*sub) * (end - start + 1));
	i = 0;
	while (i <= (end - start))
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

int		height_check(char *str, int h)
{
	int nl;
	int i;

	nl = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			nl++;
		i++;
	}
	if (h + 1 == nl)
	{
		return (nl);
	}
	else
		return (0);
}

int		characters(char *str, char *empt, char *obst, char *full)
{
	int		h;
	int		l_w;
	char	*sub;

	l_w = 0;
	while (str[l_w] != '\n')
		l_w++;
	sub = substr(0, l_w, str);
	*empt = sub[l_w - 3];
	*obst = sub[l_w - 2];
	*full = sub[l_w - 1];
	sub = substr(0, (l_w - 4), sub);
	h = ft_atoi(sub);
	if (height_check(str, h))
		return (h);
	return (0);
}

int		find_width(char *str)
{
	int		w;
	int		prev_w;
	BOOL	width_set;

	while (*str != '\n')
		str++;
	str++;
	width_set = FALSE;
	w = 0;
	prev_w = 0;
	while (*str != '\0')
	{
		w++;
		if (*str == '\n')
		{
			if (prev_w != w && width_set)
				return (0);
			width_set = TRUE;
			prev_w = w;
			w = 0;
		}
		str++;
	}
	prev_w--;
	return (prev_w);
}
