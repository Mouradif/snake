/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 04:47:39 by mkejji            #+#    #+#             */
/*   Updated: 2015/11/27 08:54:01 by mkejji           ###   ########.fr       */
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

t_snake 		*new_snake(unsigned int x, unsigned int y, char vd, char hd, char c, t_map *map)
{
	t_snake			*snake;
	unsigned int	nx;
	unsigned int	ny;

	nx = x;
	ny = y;
	nx = (hd == 'L') ? x - 1 : nx;
	nx = (hd == 'R') ? x + 1 : nx;
	ny = (vd == 'U') ? y - 1 : ny;
	ny = (vd == 'D') ? y + 1 : ny;
	snake = (t_snake*)malloc(sizeof(t_snake));
	snake->vd = vd;
	snake->hd = hd;
	snake->c = c;
	snake->map = map;
	snake->h = new_point(x, y);
	snake->h->n = new_point(nx, ny);
	return (snake);
}
