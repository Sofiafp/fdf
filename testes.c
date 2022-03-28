/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:17:36 by salegre-          #+#    #+#             */
/*   Updated: 2022/03/28 12:11:04 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int	x = 400;
	int	y = 200;

	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 800, "xoxo");
	while (x < 500)
	{
		mlx_pixel_put(mlx, mlx_win, x, y, 0x11FFFFFF);
		x++;
		y--;
	}
	while (x < 600)
	{
		mlx_pixel_put(mlx, mlx_win, x, y, 0x11FFFFFF);
		x++;
		y++;
	}
	while (x > 400)
	{
		mlx_pixel_put(mlx, mlx_win, x, y, 0x11FFFFFF);
		x--;
		y += 1.5;
	}
	while (x > 200)
	{
		mlx_pixel_put(mlx, mlx_win, x, y, 0x11FFFFFF);
		x -= 0.5;
		y--;
	}
	while (x < 300)
	{
		mlx_pixel_put(mlx, mlx_win, x, y, 0x11FFFFFF);
		x++;
		y--;
	}
	while (x < 400)
	{
		mlx_pixel_put(mlx, mlx_win, x, y, 0x11FFFFFF);
		x++;
		y++;
	}

	mlx_loop(mlx);
}
