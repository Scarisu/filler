/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 16:00:10 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/22 18:09:28 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	clean_all(t_fil *e)
{
	free(e->line);
	while (--e->p1.nb >= 0)
	{
		// printf("(%d)p1.[%d - %d]\n", e->p1.nb, e->p1.frame_list[e->p1.nb][0],
		// 			e->p1.frame_list[e->p1.nb][1]);
		free(e->p1.frame_list[e->p1.nb]);
	}
	while (--e->p2.nb >= 0)
	{
		// printf("(%d)p2.[%d - %d]\n", e->p2.nb, e->p2.frame_list[e->p2.nb][0],
		// 			e->p2.frame_list[e->p2.nb][1]);
		free(e->p2.frame_list[e->p2.nb]);
	}
	free(e->p1.frame_list);
	free(e->p2.frame_list);
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
	e->p1.player = 'o';
	e->p2.player = 'x';
	get_info(e, 1);
}
