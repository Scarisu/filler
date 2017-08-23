/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 15:58:10 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/23 05:47:01 by rlecart          ###   ########.fr       */
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
	//printf("{%c}.%d.[%d.%d]\n", p->player, p->nb, coor[0], coor[1]);
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
		add_coordinates(p, (int[2]){width - 4, height});
}

int		check_place(t_fil *e, int x, int y)
{
	int		xt;
	int		yt;
	int		pos;
	int		size;

	pos = 0;
	size = -1;
	while (++size < e->piece.size)
	{
		xt = e->piece.coor[size][0] + x + 4;
		yt = e->piece.coor[size][1] + y;
/*		printf("xt = %d\n", xt);
		printf("yt = %d\n", yt);
		printf("width = %d\n", e->map.width);
		printf("height = %d\n", e->map.height);
		printf("size = %d\n", size);
		printf("psize = %d\n", e->piece.size);
		printf("e->player = %c %c\n", e->player, e->player - 32);
*/		//sleep(2);
		if (xt > e->map.width + 4 || yt > e->map.height)
			return (-1);
//		printf("e->map.tab_map[%d][%d] = %c\n\n", yt, xt, e->map.tab_map[yt][xt]);
		if (e->map.tab_map[yt][xt] == e->player ||
			e->map.tab_map[yt][xt] == e->player - 32)
			pos++;
		if (e->map.tab_map[yt][xt] != e->player &&
			e->map.tab_map[yt][xt] != e->player - 32 &&
			e->map.tab_map[yt][xt] != '.')
			return (-1);
	}
	if (pos != 1)
		return (-1);
	return (0);
}
