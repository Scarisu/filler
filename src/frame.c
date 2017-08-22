/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 15:58:10 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/22 18:13:20 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	get_piece(t_fil *e)
{
	int		i;

	i = 8;
	get_next_line(1, &e->line) == -1 ? error(-1) : 0;
	e->map.height = ft_atoi(&e->line[i]);
	while (e->line[i++] != ' ')
		;
	e->map.width = ft_atoi(&e->line[i]);
	free(e->line);
}

void	add_coordinates(t_frame *p, int *coor)
{

	if (!(p->frame_list[p->nb] = (int *)malloc(sizeof(int) * 2)))
		error(-1);
	(p->frame_list[p->nb])[0] = coor[0];
	(p->frame_list[p->nb])[1] = coor[1];
	p->nb++;
	//printf("{%c}.%d.[%d.%d]\n", p->player, p->nb, coor[0], coor[1]);
}
