/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:21:32 by salegre-          #+#    #+#             */
/*   Updated: 2022/04/03 17:32:08 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"
#include <math.h>

// void	draw_line(t_win *base, int x, int y)
// {
// 	static int i;
// 	static int j;

// 	if (i + 200 == x)
// 	{
// 		ft_putnbr_fd(j, 1);
// 		ft_putchar_fd(' ', 1);
// 		ft_putnbr_fd(y, 1);
// 		ft_putchar_fd(' ', 1);
// 		j = y - j + 200;
// 		while (j <= y)
// 		{
// 			mlx_pixel_put(base->ptr, base->win, i, j, 0x11FFFFFF);
// 			j++;
// 		}
// 	}
// 	i = x;
// 	j = y;
// }

void	find_points(t_win *base, int x, int y, int z)
{
	int a;
	int b;

	a = (x - z)/sqrt(2) + 200;
	b = (x + 2*y + z)/sqrt(6) + 200;
	// ft_putnbr_fd(a, 1);
	// ft_putchar_fd('-', 1);
	// ft_putnbr_fd(b, 1);
	// ft_putchar_fd(' ', 1);
	mlx_pixel_put(base->ptr, base->win, b, a, 0x11FFFFFF);
	//draw_line(base, a, b);
}

void	draw(t_win *base, int **matrix)
{
	int r;
	int c;
	int i;
	int j;

	r = 0;
	i = 0;
	while (i < base->height)
	{
		c = 0;
		j = 0;
		while (j < base->weight)
		{
			find_points(base, r, c, matrix[i][j]);
			//printf("%i ", matrix[i][j]);
			//printf("%f ", r - matrix[i][j]/sqrt(20));
			j++;
			c += 20;
		}
		printf("\n");
		i++;
		r += 20;
	}	
}
