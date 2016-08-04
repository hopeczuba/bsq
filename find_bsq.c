/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hczuba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 15:34:28 by hczuba            #+#    #+#             */
/*   Updated: 2016/08/03 15:34:51 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_char_arr(char **arr, int w, int h)
{
	int r;
	int c;

	r = 0;
	while (r < h)
	{
		c = 0;
		while (c < w)
		{
			ft_putchar(arr[r][c]);
			c++;
		}
		ft_putchar('\n');
		r++;
	}
}

void	build_square(char **str_a, t_blueprint bp_, char full)
{
	int r;
	int c;

	r = bp_.r;
	c = bp_.c;
	while (r < bp_.r + bp_.max)
	{
		c = bp_.c;
		while (c < bp_.c + bp_.max)
		{
			str_a[r][c] = full;
			c++;
		}
		r++;
	}
}

int		find_max(int **arr, int w, int h)
{
	int r;
	int c;
	int	min;
	int max;

	max = 0;
	r = 1;
	while (r < h)
	{
		c = 1;
		while (c < w)
		{
			if (arr[r][c] != 0)
			{
				min = arr[r - 1][c];
				min = (arr[r - 1][c - 1] < min) ? arr[r - 1][c - 1] : min;
				min = (arr[r][c - 1] < min) ? arr[r][c - 1] : min;
				arr[r][c] = min + 1;
				max = (min + 1 > max) ? (min + 1) : max;
			}
			c++;
		}
		r++;
	}
	return (max);
}

void	start_build(t_str_array str_, t_int_array int_, char full, int *error)
{
	int			r;
	int			c;
	t_blueprint	bp_;

	bp_.max = find_max(int_.a, int_.w, int_.h);
	if (bp_.max == 0)
		(*error)++;
	r = 0;
	while (r < int_.h)
	{
		c = 0;
		while (c < int_.w)
		{
			if (int_.a[r][c] == bp_.max)
			{
				bp_.r = r - bp_.max + 1;
				bp_.c = c - bp_.max + 1;
				build_square(str_.a, bp_, full);
				return ;
			}
			c++;
		}
		r++;
	}
}

int		find_bsq(char *str)
{
	int				error;
	t_map_chars		ch_;
	t_str_array		str_;
	t_int_array		int_;

	error = 0;
	str_.h = characters(str, &ch_.empt, &ch_.obst, &ch_.full);
	if ((str_.w = find_width(str)) == 0 || str_.h == 0)
	{
		error++;
		ft_error();
		return (0);
	}
	str_ = split_str(str, str_.w, str_.h);
	int_ = integer_array(str_, ch_.empt, ch_.obst, &error);
	start_build(str_, int_, ch_.full, &error);
	if (error == 0)
		print_char_arr(str_.a, str_.w, str_.h);
	else
		ft_error();
	return (0);
}
