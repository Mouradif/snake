/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 05:00:38 by mkejji            #+#    #+#             */
/*   Updated: 2015/11/30 19:00:22 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"
#include "screen.h"
#include "libft.h"

int		snake_move(t_map map, t_snake *snake, char vdir, char hdir)
{
	relocate(snake->h);
	if (vdir == 'U')
	{
		if (snake->h->y == 0)
			return (screen_game_over());
		snake->h->y--;
	}
	if (vdir == 'D')
	{
		if (snake->h->y == map.h)
			return (screen_game_over());
		snake->h->y++;
	}
	if (hdir == 'L')
	{
		if (snake->h->x == 0)
			return (screen_game_over());
		snake->h->x--;
	}
	if (hdir == 'R')
	{
		if (snake->h->x == map.w)
			return (screen_game_over());
		snake->h->x++;
	}
	return (1);
}

int		relocate(t_snakepoint *s)
{
	if (s->n)
	{
		relocate(s->n);
		s->n->y = s->y;
		s->n->x = s->x;
	}
	return (1);
}
