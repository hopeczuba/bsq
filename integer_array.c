/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hczuba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 15:42:50 by hczuba            #+#    #+#             */
/*   Updated: 2016/08/03 15:43:13 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int				**allocate_int_a(int w, int h)
{
	int i;
	int	**arr;

	arr = malloc(sizeof(int*) * (h + 1));
	i = 0;
	while (i < h)
	{
		arr[i] = malloc(sizeof(int) * (w + 1));
		i++;
	}
	return (arr);
}

t_int_array		integer_array(t_str_array str_, char empt, char obst, int *e)
{
	int			r;
	int			c;
	t_int_array	int_;

	int_.w = str_.w;
	int_.h = str_.h;
	int_.a = allocate_int_a(int_.w, int_.h);
	r = 0;
	while (r < int_.h)
	{
		c = 0;
		while (c < int_.w)
		{
			if (str_.a[r][c] == empt)
				int_.a[r][c] = TRUE;
			else if (str_.a[r][c] == obst)
				int_.a[r][c] = FALSE;
			else
				(*e)++;
			c++;
		}
		r++;
	}
	return (int_);
}
