/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:34:15 by salegre-          #+#    #+#             */
/*   Updated: 2022/03/30 19:15:31 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int		key_hook(int keycode, int *i)
{	
	if (keycode == 53)
		*i = 1;
	return (0);
}

void	create_window(t_win **base, int weight, int height)
{
	(*base)->ptr = mlx_init();
	(*base)->win = mlx_new_window((*base)->ptr, weight * 50, height * 50, "xoxo");
	(*base)->weight = weight;
	(*base)->height = height;
}
