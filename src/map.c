/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:30:55 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/28 15:36:06 by pbernier         ###   ########.fr       */
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
	while (++height < e->map.height && e->sw == 1)
	{
		while (e->map.tab_map[++width])
		{
			if (e->map.tab_map[height][width] == 'X')
				add_coordinates(&e->p2, (int[2]){height, width - 4});
			else if (e->map.tab_map[height][width] == 'O')
				add_coordinates(&e->p1, (int[2]){height, width - 4});
		}
		width = 3;
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
