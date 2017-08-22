/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 16:00:10 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/23 00:39:54 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	clean_all(t_fil *e)
{
	free(e->line);
	free(e->p1.frame_list);
	free(e->p2.frame_list);
}

void	reset_all(t_fil *e)
{
	e->piece.height = 0;
	e->piece.width = 0;
	while (--e->piece.size >= 0)
		free(e->piece.coor[e->piece.size]);
	e->piece.size = 0;
	free(e->piece.coor);
	while (--e->p1.nb >= 0)
		free(e->p1.frame_list[e->p1.nb]);
	e->p1.nb = 0;
	while (--e->p2.nb >= 0)
		free(e->p2.frame_list[e->p2.nb]);
	e->p2.nb = 0;
}

void	clean_piece(t_piece *piece)
{
	int		tmp;

	tmp = piece->height;
	while (--tmp >= 0)
		free(piece->tab_piece[tmp]);
	free(piece->tab_piece);
}

void	init(t_fil *e)
{
	int		max_poss;

	get_map_size(e);
	max_poss = e->map.height * e->map.width;
	if (!(e->p1.frame_list = (int **)malloc(sizeof(int*) * max_poss)))
		error(-1);
	if (!(e->p2.frame_list = (int **)malloc(sizeof(int*) * max_poss)))
		error(-1);
	e->p1.nb = 0;
	e->p2.nb = 0;
	e->piece.size = 0;
	e->p1.player = 'o';
	e->p2.player = 'x';
	e->piece.tab_piece = NULL;
}
