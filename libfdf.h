/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:38:43 by salegre-          #+#    #+#             */
/*   Updated: 2022/04/11 15:45:01 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFDF_H
# define LIBFDF_H

// DELETE THIS AFTER ? ///
# define normal  "\x1B[0m"
# define red  "\x1B[31m"
# define green  "\x1B[32m"
# define yellow  "\x1B[33m"
# define blue  "\x1B[34m"
# define magenta  "\x1B[35m"
# define cyan  "\x1B[36m"
# define white  "\x1B[37m"
///////////////////////////

# include "minilibx_macos/mlx.h"
# include "get_next_line/libgnl.h"
# include "libft/libft.h"
# include <fcntl.h>
///APAGAR DEPOIS
#include <stdio.h>
////
typedef struct s_win
{
	void	*ptr;
	void	*win;
	int		weight;
	int		height;
	int		win_height;
	int		win_weight;
}	t_win;

typedef struct s_points
{
	int i;
	int j;
	int x;
	int y;
	int	x_a;
	int	y_a;
	int	x_b;
	int	y_b;
	int	x_c;
	int	y_c;
	int	x_steps;
	int	y_steps;
	float	add;
	float	res;
}	t_points;

void	create_window(t_win **base, int weight, int height);
void	draw(t_win *ptr, int **matrix);
int		key_hook(int keycode, int *i);

#endif

