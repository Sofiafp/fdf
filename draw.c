/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:21:32 by salegre-          #+#    #+#             */
/*   Updated: 2022/03/30 22:35:21 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"
#include <math.h>

void	draw_line(t_win *base, int x, int y, int z)
{
	//x'=(x-z)/sqrt(2)
	//y'=(x+2y+z)/sqrt(686)
	//(void)base;
	int a;
	int b;
	// (void)z;
	a = (x - z)/sqrt(2) + 200;
	b = (x + 2*y + z)/sqrt(6) + 200;
	// a = x + 100;
	// b = y + 100;
	//int d = x + 100;
	//mlx_pixel_put(base->ptr, base->win, a, c, 0x11FFFFFF);
	ft_putnbr_fd(a, 1);
	ft_putchar_fd('-', 1);
	ft_putnbr_fd(b, 1);
	ft_putchar_fd(' ', 1);
	mlx_pixel_put(base->ptr, base->win, b, a, 0x11FFFFFF);
}

void	draw(t_win *base, int **matrix)
{
	int r;
	int c;
	int i;
	int j;
	(void)matrix;

	r = 0;
	i = 0;
	while (i < base->height)
	{
		c = 0;
		j = 0;
		while (j < base->weight)
		{
			draw_line(base, r, c, matrix[i][j]);
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
