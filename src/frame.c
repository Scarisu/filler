/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 15:58:10 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/24 16:25:08 by pbernier         ###   ########.fr       */
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
	//printf("  {[%d - %d]}\n", height, width);
	while (++size < e->piece.size)
	{
		t_height = e->piece.coor[size][0] + height;
		t_width = e->piece.coor[size][1] + width + 4;
		//printf("%d.[%d-%d]\n", size, e->piece.coor[size][0], e->piece.coor[size][1]);
		//printf("{%d.%d}[%c]\n", t_height, t_width - 4, e->map.tab_map[t_height][t_width]);
		if (t_width >= e->map.width + 4 || t_height >= e->map.height)
		{
			//printf("invalide : %d >= %d | %d >= %d\n", t_width, e->map.width + 4, t_height, e->map.height);
			return (-1);
		}
		if (e->map.tab_map[t_height][t_width] == e->player ||
			e->map.tab_map[t_height][t_width] == e->player - 32)
			poss++;
		if (e->map.tab_map[t_height][t_width] != e->player &&
			e->map.tab_map[t_height][t_width] != e->player - 32 &&
			e->map.tab_map[t_height][t_width] != '.')
		{
			//printf("enemy\n");
			return (-1);
		}
	}
	//printf("%d - Ok\n", poss);
	if (poss != 1)
		return (-1);
	return (0);
}
