/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:30:55 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/23 01:04:26 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	get_info(t_fil *e)
{
	int		i;
	int		height;

	i = 3;
	height = -1;
	get_next_line(1, &e->line) == -1 ? error(-1) : 0;
	ft_memdel((void**)&e->line);
	while (++height < e->map.height)
	{
		get_next_line(1, &e->line) == -1 ? error(-1) : 0;
		while (e->line[++i])
		{
			if (e->line[i] == 'x' || e->line[i] == 'X')
				add_coordinates(&e->p1, (int[2]){i - 4, height});
			else if (e->line[i] == 'o' || e->line[i] == 'O')
				add_coordinates(&e->p2, (int[2]){i - 4, height});
		}
		i = 3;
		ft_memdel((void**)&e->line);
	}
}

void	get_map_size(t_fil *e)
{
	int		i;

	i = 8;
	get_next_line(1, &e->line) == -1 ? error(-1) : 0;
	if (e->line[0] != 'P')
		error(0);
	e->map.height = ft_atoi(&e->line[i]);
	while (e->line[i++] != ' ')
		;
	e->map.width = ft_atoi(&e->line[i]);
}
