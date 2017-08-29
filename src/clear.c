/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 02:34:03 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/29 10:50:41 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	clean_tab_map(t_map *map)
{
	int		tmp;

	tmp = map->height;
	while (--tmp >= 0)
		ft_memdel((void**)&map->tab_map[tmp]);
	ft_memdel((void**)&map->tab_map);
}

void	clean_tab_piece(t_piece *piece)
{
	int		tmp;

	tmp = piece->height;
	while (--tmp >= 0)
		ft_memdel((void**)&piece->tab_piece[tmp]);
	ft_memdel((void**)&piece->tab_piece);
}

void	clean_frame_list(t_fil *e)
{
	while (--e->p1.nb >= 0)
		ft_memdel((void**)&e->p1.frame_list[e->p1.nb]);
	e->p1.nb = 0;
	while (--e->p2.nb >= 0)
		ft_memdel((void**)&e->p2.frame_list[e->p2.nb]);
	e->p2.nb = 0;
	ft_memdel((void**)&e->p1.frame_list);
	ft_memdel((void**)&e->p2.frame_list);
}

void	clean_piece(t_piece *piece)
{
	piece->height = 0;
	piece->width = 0;
	while (--piece->size >= 0)
		ft_memdel((void**)&piece->coor[piece->size]);
	piece->size = 0;
	ft_memdel((void**)&piece->coor);
}
