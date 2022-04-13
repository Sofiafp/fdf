/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:02:35 by salegre-          #+#    #+#             */
/*   Updated: 2022/04/11 16:24:33 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"
#include <math.h>

// void	go_up(t_win )
// {
	
// }

void	draw_horizontals(t_win *ptr, t_points *pt, int **matrix)
{
	pt->x_b = (pt->x + 25 - matrix[pt->i][pt->j + 1])/sqrt(2);
	pt->y_b = (pt->x + 25 - 2*(pt->y) + matrix[pt->i][pt->j + 1])/sqrt(6);

	pt->x_steps = pt->x_b - pt->x_a;
	pt->y_steps = pt->y_b - pt->y_a;
	(void)ptr;
	// if (pt->y_steps > 0)
	// 	go_up(ptr, pt);
	// else if (pt->y_steps < 0)
	// 	go_down(ptr, pt);
	// else
	// 	go_straight(ptr, pt);
}

void	find_points(t_win *ptr, int **matrix, int x, int y)
{
	(void)x;
	(void)y;
	t_points	*pt;
	static int s_i;
	static int s_j;
	
	pt = malloc(sizeof(t_points));

	pt->x_a = (x - matrix[s_i][s_j]) / sqrt(2);
	pt->y_a = (x + 2*y + matrix[s_i][s_j]) / sqrt(6); 
	pt->i = s_i;
	pt->j = s_j;
	pt->x = x;
	pt->y = y;
	// int x_a_ = x_a;
	// int y_a_ = y_a;

//	if (s_j + 1 != ptr->weight)
//	{
		//draw_horizontals(ptr, pt, matrix);
	mlx_pixel_put(ptr, ptr->win, pt->x_a, pt->y_a, 0x11FFFFFF);
//	}
	
	free(pt);
	if (s_j == ptr->weight - 1)
	{
		s_j = 0;
		s_i++;
	}
	else
		s_j++;
}

void	draw(t_win *ptr, int **matrix)
{
	int	x;
	int	y;
	int	steps;
	int x_barrier;
	int y_barrier;	
	(void)matrix;
	
	if (ptr->height > (3*ptr->weight)/4)
	{
		steps = ((ptr->win_height * 4)/6)/ptr->height;
		y_barrier = ptr->win_height/6;
		x_barrier = (ptr->win_weight - steps*ptr->weight)/2;
	}
	else
	{
		steps = ((ptr->win_weight * 4)/6)/ptr->weight;
		y_barrier = (ptr->win_height - steps*ptr->height)/2;
		x_barrier = ptr->win_weight/6;
	}
	y = 0;
	while (y != (ptr->height)*steps)
	{
		x = 0;
		while (x != (ptr->weight)*steps)
		{
			find_points(ptr, matrix, x + x_barrier, y + y_barrier);
			x += steps;
		}
		y += steps;
	}
}
