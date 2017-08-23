/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 20:26:02 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/23 05:16:39 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>
/*
void	print_result(t_fil *e)
{
	// printf("%d.%d [%d.%d] [%d.%d]\n", e->piece.height, e->piece.width,
	// 	e->piece.coor[0][0], e->piece.coor[0][1],
	// 	e->piece.coor[1][0], e->piece.coor[1][1]);

	int		k;

	k = -1;
	while (++k < e->p1.nb)
		printf("p1.{%d.%d}\n", e->p1.frame_list[k][0], e->p1.frame_list[k][1]);
	k = -1;
	while (++k < e->p2.nb)
		printf("p2.{%d.%d}\n", e->p2.frame_list[k][0], e->p2.frame_list[k][1]);
	reset_all(e);
}
*/

void	result(t_fil *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->map.height)
	{
		x = -1;
		while (++x < e->map.width)
		{
			if (!(check_place(e, x, y)))
			{
				clean_tab_map(&e->map);
				reset_all(e);
				printf("%d %d\n", x, y);
				return ;
			}
		}
	}
	clean_tab_map(&e->map);
	reset_all(e);
	printf("%d %d\n", 0, 0);
}
