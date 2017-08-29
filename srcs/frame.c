/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 15:58:10 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/29 13:51:08 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	add_coordinates_player(t_frame *p, int *coor)
{
	if (!(p->frame_list[p->nb] = (int *)malloc(sizeof(int) * 2)))
		error(-1);
	p->frame_list[p->nb][0] = coor[0];
	p->frame_list[p->nb][1] = coor[1];
	p->nb++;
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

int		parser(t_fil *e, int y, int x)
{
	int	height;
	int	width;
	int cercle;

	cercle = 0;
	while (cercle < e->map.height || cercle < e->map.width)
	{
		height = y - cercle - 1;
		while (++height < y + cercle + 1)
		{
			width = x - cercle - 1;
			while (++width < x + cercle + 1)
				if (height >= 0 && height < e->map.height &&
					width >= 0 && width < e->map.width &&
					!check_place(e, height, width))
				{
					print_result(e, height, width, 0);
					return (0);
				}
		}
		++cercle;
	}
	return (1);
}
