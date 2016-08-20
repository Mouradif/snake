/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 04:47:39 by mkejji            #+#    #+#             */
/*   Updated: 2015/11/30 19:19:22 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "snake.h"

t_map			*new_map(unsigned int width, unsigned int height, char terrain)
{
	t_map			*map;
	char			**grid;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	map = (t_map*)malloc(sizeof(t_map));
	grid = (char**)malloc(sizeof(char*) * height);
	while (i < height)
	{
		grid[i] = malloc(sizeof(char) * width);
		while (j < width)
			grid[i][j++] = terrain;
		j = 0;
		i++;
	}
	map->w = width;
	map->h = height;
	map->g = grid;
	return (map);
}

t_snakepoint	*new_point(unsigned int x, unsigned int y)
{
	t_snakepoint	*point;

	point = (t_snakepoint*)malloc(sizeof(t_snakepoint));
	point->x = x;
	point->y = y;
	point->n = (t_snakepoint*)0;
	return (point);
}

t_snake 		*new_snake(unsigned int x, unsigned int y, char vd, char hd, char hc, char c, t_map *map, unsigned int size)
{
	t_snake			*snake;
	t_snakepoint	*point;

	snake = (t_snake*)malloc(sizeof(t_snake));
	snake->vd = vd;
	snake->hd = hd;
	snake->c = c;
	snake->hc = hc;
	snake->map = map;
	point = new_point(x, y);
	snake->h = point;
	while (size)
	{
		x = (hd == 'R') ? x - 1 : x;
		x = (hd == 'L') ? x + 1 : x;
		y = (vd == 'D') ? y - 1 : y;
		y = (vd == 'U') ? y + 1 : y;
		point->n = new_point(x, y);
		point = point->n;
		size--;
	}
	return (snake);
}
