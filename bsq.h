/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hczuba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 18:39:44 by hczuba            #+#    #+#             */
/*   Updated: 2016/08/03 18:39:45 by hczuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <unistd.h>
# include <stdlib.h>
# define BOOL int
# define TRUE 1
# define FALSE 0

typedef	struct	s_int_array {
	int **a;
	int w;
	int	h;
}				t_int_array;

typedef	struct	s_str_array {
	char	**a;
	int		w;
	int		h;
}				t_str_array;

typedef	struct	s_blueprint	{
	int max;
	int	r;
	int c;
}				t_blueprint;

typedef	struct	s_map_chars {
	char empt;
	char obst;
	char full;
}				t_map_chars;

void			ft_error(void);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
int				ft_strlen(char *str);
int				find_bsq(char *str);
int				ft_atoi(char *str);
t_str_array		split_str(char *str, int w, int h);
int				find_width(char *str);
int				characters(char *str, char *empt, char *obst, char *full);
t_int_array		integer_array(t_str_array str_, char empt, char obst, int *e);

#endif
