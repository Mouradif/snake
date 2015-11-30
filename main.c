/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 08:24:36 by mkejji            #+#    #+#             */
/*   Updated: 2015/11/30 19:22:42 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <termios.h>
#include "libft.h"
#include "snake.h"
#include "screen.h"

int	main(void)
{
	t_map *m;
	t_snake *s;
	int c;
	struct termios info;

	tcgetattr(0, &info);
	info.c_lflag &= ~ICANON;
	info.c_cc[VMIN] = 1;
	info.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &info);
	m = new_map(200, 50, '.');
	s = new_snake(2, 2, 'U', 'L', '*', '#', m, 15);
	display_map(m, s);
	c = 1;
	while (c)
	{
		c = getchar();
		if (c == 'k')
			break ;
		if (c == 'w')
			snake_move(*m, s, 'U', 0);
		if (c == 'a')
			snake_move(*m, s, 0, 'L');
		if (c == 'x')
			snake_move(*m, s, 'D', 0);
		if (c == 'd')
			snake_move(*m, s, 0, 'R');
		if (c == 'q')
			snake_move(*m, s, 'U', 'L');
		if (c == 'e')
			snake_move(*m, s, 'U', 'R');
		if (c == 'z')
			snake_move(*m, s, 'D', 'L');
		if (c == 'c')
			snake_move(*m, s, 'D', 'R');
		display_map(m, s);
	}
}
