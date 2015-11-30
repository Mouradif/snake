/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 04:48:15 by mkejji            #+#    #+#             */
/*   Updated: 2015/11/30 19:18:27 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_H
# define SNAKE_H

// n : next
typedef struct				s_snakepoint
{
	unsigned int			x;
	unsigned int			y;
	struct s_snakepoint		*n;
}							t_snakepoint;

// t : type
typedef struct				s_food
{
	unsigned int			x;
	unsigned int			y;
	unsigned char			t;
}							t_food;

// w : width, h : height, t : char representing floor, f : food, g : grid
typedef struct				s_map
{
	unsigned int			w;
	unsigned int			h;
	char					t;
	char					**g;
}							t_map;

// st : status, etn : has_just_eaten (0 / 1)
// vh : vertical direction, hd : horizontal direction
// c : char representing body, f : facing direction, h : head
typedef struct				s_snake
{
	unsigned char			status;
	unsigned char			has_just_eaten;
	char					c;
	char					hc;
	char					vd;
	char					hd;
	struct s_snakepoint		*h;
	struct s_map			*map;	
}							t_snake;


int				snake_move(t_map map, t_snake *snake, char vdir, char hdir);
int				relocate(t_snakepoint *s);
t_map			*new_map(unsigned int width, unsigned int height, char terrain);
t_snakepoint	*new_point(unsigned int x, unsigned int y);
t_snake 		*new_snake(unsigned int x, unsigned int y,
					char vd, char hd, char hc, char c, t_map *map, unsigned int size);
void			display_map(const t_map *m, const t_snake *s);
char			in_spot(unsigned int x, unsigned int y, const t_snakepoint *s);

#endif
