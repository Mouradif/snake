/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 08:00:12 by mkejji            #+#    #+#             */
/*   Updated: 2015/11/30 19:12:10 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"
#include "libft.h"

void	display_map(const t_map *m, const t_snake *s)
{
	unsigned int	i;
	unsigned int	j;
	char			c;

	i = 0;
	j = 0;
	while (i < m->h)
	{
		while (j < m->w)
		{
			if (in_spot(j, i, s->h))
				c = (i == s->h->y && j == s->h->x) ? s->hc : s->c;
			else
				c = m->g[i][j];
			ft_putchar(c);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}
