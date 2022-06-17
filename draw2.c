/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:02:35 by salegre-          #+#    #+#             */
/*   Updated: 2022/06/17 17:33:58 by salegre-         ###   ########.fr       */
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

//	if (s_j + 1 != ptr->width)
//	{
		//draw_horizontals(ptr, pt, matrix);
		// int n = 30;
	// while (n--)
	// {
		mlx_pixel_put(ptr, ptr->win, pt->x_a + ptr->x_barrier , pt->y_a + ptr->y_barrier, 0x11FFFFFF);
	// 	pt->x_a++;
	// }
//	}
	free(pt);
	if (s_j == ptr->width - 1)
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
	
	if (ptr->height > (3*ptr->width)/4)
	{
		
		steps = ((ptr->win_height * 4)/6)/ptr->height;
		ptr->y_barrier = ptr->win_height/6;
		ptr->x_barrier = (ptr->win_width - steps*ptr->width)/2;
	}
	else
	{
		steps = ((ptr->win_width * 6)/8)/ptr->width;
		ptr->y_barrier = (ptr->win_height - steps*ptr->height)/2;
		ptr->x_barrier = ptr->win_width/8;
	}
	y = 0;
	while (y != (ptr->height)*steps)
	{
		x = 0;
		while (x != (ptr->width)*steps)
		{
		//	mlx_pixel_put(ptr, ptr->win, x + ptr->x_barrier , y + ptr->y_barrier, 0x11FFFFFF);

			find_points(ptr, matrix, x, y);
			x += steps;
		}
		y += steps;
	}
}
