/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:02:35 by salegre-          #+#    #+#             */
/*   Updated: 2022/04/05 22:15:32 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"
#include <math.h>

void	find_points(t_win *ptr, int **matrix, int x, int y)
{
	(void)matrix;
	static int	i;
	static int	j;
	//ft_putnbr_fd(matrix[i][j], 1);
	int x_a = (x - matrix[i][j]) / sqrt(2);
	int y_a = (x + 2*y + matrix[i][j]) / sqrt(6);
	// int x_a_ = x_a;
	// int y_a_ = y_a;

	if (j + 1 != ptr->weight)
	{
		int x_b = (x + 25 - matrix[i][j + 1]) / sqrt(2);
		int y_b = (x +25 + 2*y + matrix[i][j + 1]) / sqrt(6);

		//float add = (y_b - y_a)/(x_b - x_a);
		//float res = 0;
		while (x_a != x_b)
		{
			// ft_putstr_fd("OIOI", 1);
			mlx_pixel_put(ptr, ptr->win, y_a, x_a, 0x11FFFFFF);
			y_a++;
		}
	}
	// if (i + j != ptr->height)
	// {
	// 	int x_c = (x - matrix[i][j + 1]) / sqrt(2);
	// 	while (x_a_ != x_c)
	// 	{
	// 		// ft_putstr_fd("OIOI", 1);
	// 		mlx_pixel_put(ptr, ptr->win, y_a_, x_a_, 0x11FFFFFF);
	// 		x_a_++;
	// 	}				
	// } 
	//mlx_pixel_put(ptr, ptr->win, y_a, x_a, 0x11FFFFFF);
	if (j == ptr->weight - 1)
	{
		j = 0;
		i++;
	}
	else
		j++;
}

void	draw(t_win *ptr, int **matrix)
{
	int	x;
	int	y;
	
	y = 0;
	while (y != ptr->height*25)
	{
		x = 0;
		while (x != ptr->weight*25)
		{
			find_points(ptr, matrix, y + 150, x + 100);
			x += 25;
		}
		y += 25;
	}
}
