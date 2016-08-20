/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 08:03:40 by mkejji            #+#    #+#             */
/*   Updated: 2015/11/27 08:39:15 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

char	in_spot(unsigned int x, unsigned int y, const t_snakepoint *s)
{
	if (!(s->n) && (s->x != x || s->y != y))
		return (0);
	if (s->x == x && s->y == y)
		return (1);
	return (in_spot(x, y, s->n));
}
