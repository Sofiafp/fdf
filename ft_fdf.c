/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:20:44 by salegre-          #+#    #+#             */
/*   Updated: 2022/03/29 22:28:14 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int	get_height(char *file)
{
	char	*line;
	int 	fd;
	int		height;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	height = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		height++;		
	}
	close(fd);
	return (height);
}

int	get_weight(char *file)
{
	char 	**line;
	int 	fd;
	int 	weight;
	
	fd = open(file, O_RDONLY);
	line = ft_split(get_next_line(fd), ' ');
	weight = 0;
	while (line[weight] != NULL)
	{
		weight++;
	}
	free(line);
	close(fd);
	return (weight);
}

int	**create_matrix(char *file, int height, int weight)
{
	int	**matrix;
	int i;
	char	**line;
	int		fd;
	int		j;

	fd = open(file, O_RDONLY);
	matrix = malloc((height + 1) * sizeof(int *));
	if (!matrix)
		return (0);
	i = 0;
	while (i != height)
	{
		line = ft_split(get_next_line(fd), ' ');
		matrix[i] = malloc((weight + 1) * sizeof(int));
		j = 0;
		while (j != weight)
		{
			matrix[i][j] = ft_atoi(line[j]);
			j++;
		}
		i++;
	}
	return (matrix);
}

int main(int argc , char **file)
{
	t_win	*base;
	int		**mtx;
	int		height;
	int		weight;
	
	if (argc < 2 || argc > 2)
		return (0);
	height = get_height(file[1]);
	weight = get_weight(file[1]);
	mtx = create_matrix(file[1], height, weight);
	base = malloc(sizeof(t_win));
	create_window(&base, weight, height);
	draw(base, mtx);
	mlx_key_hook(base->win, key_pressed, (void *)13);
	mlx_loop(base->ptr);
	return(0);
}
