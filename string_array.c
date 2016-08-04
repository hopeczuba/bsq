/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hczuba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 15:29:32 by hczuba            #+#    #+#             */
/*   Updated: 2016/08/03 15:30:57 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void			populate(char **new, char *str, int w, int h)
{
	int r;
	int c;

	w++;
	while (*str != '\n')
		str++;
	str++;
	r = 0;
	while (r < h)
	{
		c = 0;
		while (c < w)
		{
			new[r][c] = str[w * r + c];
			c++;
		}
		r++;
	}
	new[r][c] = '\0';
}

t_str_array		split_str(char *str, int w, int h)
{
	int				i;
	t_str_array		new_;

	new_.a = malloc(sizeof(char*) * (h + 1));
	i = 0;
	while (i <= h)
	{
		new_.a[i] = malloc(sizeof(char) * (w + 1));
		i++;
	}
	populate(new_.a, str, w, h);
	new_.w = w;
	new_.h = h;
	return (new_);
}
