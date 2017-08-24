/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:30:55 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/24 14:45:18 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	get_info(t_fil *e)
{
	int		width;
	int		height;

	width = 3;
	height = -1;
	get_next_line(1, &e->line) == -1 ? error(-1) : 0;
	ft_memdel((void**)&e->line);
	init_tab_map(&e->map);
	while (++height < e->map.height)
	{
		while (e->map.tab_map[++width])
		{
			if (e->map.tab_map[height][width] == 'x' ||
				e->map.tab_map[height][width] == 'X')
				check_around(&e->map, &e->p2, height, width);
			else if (e->map.tab_map[height][width] == 'o' ||
					 e->map.tab_map[height][width] == 'O')
				check_around(&e->map, &e->p1, height, width);
		}
		width = 3;
	}
}

void	get_map_size(t_fil *e)
{
	int		i;

	i = 8;
	get_next_line(1, &e->line) == -1 ? error(-1) : 0;
	if (e->line[0] != 'P')
		error(0);
	e->map.height = ft_atoi(&e->line[i]);
	while (e->line[i++] != ' ')
		;
	e->map.width = ft_atoi(&e->line[i]);
}
