/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:21:32 by salegre-          #+#    #+#             */
/*   Updated: 2022/03/29 22:19:09 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	draw_line(t_win *base, int r, int c)
{
	int n = 10;
	int x = r;
	int y = c;
	while (n--)
	{
		mlx_pixel_put(base->ptr, base->win,r++ + 200, y + 100, 0x11FFFFFF);
	}
	n = 10;
	while (n--)
	{
		mlx_pixel_put(base->ptr, base->win, x + 200, y++ + 100, 0x11FFFFFF);
	}
}

void	draw(t_win *base, int **matrix)
{
	int r;
	int c;
	(void)matrix;

	r = 0;
	while (r < base->height*10)
	{
		c = 0;
		while (c < base->weight*10)
		{
			draw_line(base, r, c);
			c += 10;
		}
		printf("%d\n", r);
		r += 10;
		r++;
	}	
}
