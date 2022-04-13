/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:20:44 by salegre-          #+#    #+#             */
/*   Updated: 2022/04/11 15:51:28 by salegre-         ###   ########.fr       */
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
	while (line != NULL && line[0] != '\n')
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
	while (line[weight] != NULL && line[weight][0] != '\n')
		weight++;
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
		return (NULL);
	i = 0;
	while (i != height)
	{
		line = ft_split(get_next_line(fd), ' ');
		matrix[i] = malloc((weight + 1) * sizeof(int));
		if (!matrix)
			return (NULL);
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
	(void)file;
	
	if (argc != 2)
		return (0);
	height = get_height(file[1]);
	weight = get_weight(file[1]);
	base = malloc(sizeof(t_win));
	if (!base)
		return (0);
	create_window(&base, weight, height);
	mtx = create_matrix(file[1], height, weight);
	if (!mtx)
		return (0);
	draw(base, mtx);
	free(mtx);
	mlx_loop(base->ptr);
	free(base);
	return(0);
}
