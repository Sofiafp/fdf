/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:02:35 by salegre-          #+#    #+#             */
/*   Updated: 2022/04/03 18:09:32 by salegre-         ###   ########.fr       */
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

	if (j + 1 != ptr->weight)
	{
		int x_b = (x - matrix[i][j + 1]) / sqrt(2);
		int y_b = (x - matrix[i][j + 1]) / sqrt(2);
	}

	mlx_pixel_put(ptr, ptr->win, y_a, x_a, 0x11FFFFFF);
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
