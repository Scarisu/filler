/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:30:55 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/21 18:59:48 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	add_coordinates(t_frame *p, int *coor)
{
	if (!(p->frame_list[p->nb] = (int *)malloc(sizeof(int) * 2)))
		error(-1);
	(p->frame_list[p->nb])[0] = coor[0];
	(p->frame_list[p->nb])[1] = coor[1];
	//printf("{%d - %d}\n", (p->frame_list[p->nb])[0], (p->frame_list[p->nb])[1]);
	p->nb++;
}

void	get_info(t_fil *e)
{
	int		i;
	int		height;
	char	*line;

	i = 3;
	height = -1;
	get_next_line(1, &line) == -1 ? error(-1) : 0;
	free(line);
	while (++height < e->map.height)
	{
		get_next_line(1, &line) == -1 ? error(-1) : 0;
		while (line[++i])
		{
			if (line[i] == 'o')
				add_coordinates(&e->p1, (int[2]){i - 4, height});
			else if (line[i] == 'x')
				add_coordinates(&e->p2, (int[2]){i - 4, height});
		}
		i = 3;
		free(line);
	}
	e += 0;
}

void	get_map(t_map *map)
{
	int		i;
	char	*line;

	i = 8;
	get_next_line(1, &line) == -1 ? error(-1) : 0;
	map->height = ft_atoi(&line[i]);
	while(line[i++] != ' ')
		;
	map->width = ft_atoi(&line[i]);
	printf("[%d][%d]\n", map->height, map->width);
	free(line);
}
