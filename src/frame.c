/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 15:58:10 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/26 14:39:23 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	add_coordinates(t_frame *p, int *coor)
{
	if (!(p->frame_list[p->nb] = (int *)malloc(sizeof(int) * 2)))
		error(-1);
	p->frame_list[p->nb][0] = coor[0];
	p->frame_list[p->nb][1] = coor[1];
	p->nb++;
}

void	check_around(t_map *map, t_frame *p, int height, int width)
{
	int		out;

	out = 0;
	if (height > 0 &&
		map->tab_map[height - 1][width] != p->player &&
		map->tab_map[height - 1][width] != p->player - 32)
		++out;
	else if (width > 4 &&
		map->tab_map[height][width - 1] != p->player &&
		map->tab_map[height][width - 1] != p->player - 32)
		++out;
	else if (height < map->height - 1 &&
		map->tab_map[height + 1][width] != p->player &&
		map->tab_map[height + 1][width] != p->player - 32)
		++out;
	else if (width < map->width + 3 &&
		map->tab_map[height][width + 1] != p->player &&
		map->tab_map[height][width + 1] != p->player - 32)
		++out;
	if (out != 0)
		add_coordinates(p, (int[2]){height, width - 4});
}

int		check_place(t_fil *e, int height, int width)
{
	int		t_width;
	int		t_height;
	int		poss;
	int		size;

	poss = 0;
	size = -1;
	while (++size < e->piece.size)
	{
		t_height = e->piece.coor[size][0] + height;
		t_width = e->piece.coor[size][1] + width + 4;
		if (t_width >= e->map.width + 4 || t_height >= e->map.height)
			return (-1);
		if (e->map.tab_map[t_height][t_width] == e->player ||
			e->map.tab_map[t_height][t_width] == e->player - 32)
			poss++;
		if (e->map.tab_map[t_height][t_width] != e->player &&
			e->map.tab_map[t_height][t_width] != e->player - 32 &&
			e->map.tab_map[t_height][t_width] != '.')
			return (-1);
	}
	if (poss != 1)
		return (-1);
	return (0);
}
