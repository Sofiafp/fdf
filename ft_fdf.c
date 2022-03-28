/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:20:44 by salegre-          #+#    #+#             */
/*   Updated: 2022/03/28 23:08:13 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"
#include <stdio.h>

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
			//printf("%s ", line[j]);
			//printf("%d ", matrix[i][j]);
			j++;
		}
		i++;
	}
	return (matrix);
}

int main(int argc , char **file)
{	
	//int		fd;
	//char	*line;
	int		height;
	int		weight;
	int		**line_matrix;
	
	if (argc < 2 || argc > 3)
		return (0);
	weight = get_weight(file[1]);
	height = get_height(file[1]);
	int i = 0;
	int j;
	line_matrix = create_matrix(file[1], height, weight);
	while (i < height)
	{
		j = 0;
		while (j < weight)
		{
			printf("%s%d%s ",red, line_matrix[i][j], normal);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("height: %d\n", height);
	printf("weight: %d\n", weight);
	return(0);
}
