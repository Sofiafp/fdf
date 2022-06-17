/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:34:15 by salegre-          #+#    #+#             */
/*   Updated: 2022/04/21 10:10:03 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int		key_hook(int keycode, int *i)
{	
	if (keycode == 53)
		*i = 1;
	return (0);
}

void	create_window(t_win **base, int width, int height)
{
	(*base)->ptr = mlx_init();
	(*base)->width = width;
	(*base)->height = height;
	(*base)->win = mlx_new_window((*base)->ptr, 1000, 750, "xoxo");
	(*base)->win_width = 1000;
	(*base)->win_height = 750;
}
