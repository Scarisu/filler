/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 15:58:10 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/23 01:00:31 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	add_coordinates(t_frame *p, int *coor)
{
	if (!(p->frame_list[p->nb] = (int *)malloc(sizeof(int) * 2)))
		error(-1);
	(p->frame_list[p->nb])[0] = coor[0];
	(p->frame_list[p->nb])[1] = coor[1];
	p->nb++;
	//printf("{%c}.%d.[%d.%d]\n", p->player, p->nb, coor[0], coor[1]);
}
