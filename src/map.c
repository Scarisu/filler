/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:30:55 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/26 16:25:15 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	get_info(t_fil *e)
{
	int		width;
	int		height;

	width = 3;
	height = -1;
	sp_gnl(&e->line) == -1 ? error(-1) : 0;
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
		if (e->parser[1] == 0)
			witch_way(e);
	}
}

void	get_map_size(t_fil *e)
{
	int		i;

	i = 8;
	sp_gnl(&e->line) == -1 ? error(-1) : 0;
	if (e->line[0] != 'P')
		error(0);
	e->map.height = ft_atoi(&e->line[i]);
	while (e->line[i++] != ' ')
		;
	e->map.width = ft_atoi(&e->line[i]);
}
