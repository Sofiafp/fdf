/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:34:15 by salegre-          #+#    #+#             */
/*   Updated: 2022/03/29 22:29:44 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int		key_pressed(int keycode, void *param)
{
	printf("key code: %d\t- param: %p\n", keycode, param);
	return (0);
}

void	create_window(t_win **base, int weight, int height)
{
	(*base)->ptr = mlx_init();
	(*base)->win = mlx_new_window((*base)->ptr, weight * 50, height * 50, "xoxo");
	(*base)->weight = weight;
	(*base)->height = height;
}
