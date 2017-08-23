/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 20:26:02 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/23 07:55:02 by pbernier         ###   ########.fr       */
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

int		result(t_fil *e)
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
				ft_putstr(ft_itoa(y));
				ft_putstr(" ");
				ft_putstr(ft_itoa(x));
				ft_putstr("\n");
				//printf("%d %d\n", x, y);
				return (0);
			}
		}
	}
	clean_tab_map(&e->map);
	reset_all(e);
	ft_putstr(ft_itoa(0));
	ft_putstr(" ");
	ft_putstr(ft_itoa(0));
	ft_putstr("\n");
	return (1);
}
