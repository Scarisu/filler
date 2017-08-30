/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:30:55 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/30 20:17:19 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	get_info(t_fil *e)
{
	int		width;
	int		height;

	width = 3;
	height = -1;
	sp_gnl(&e->line) == -1 ? error(-1) : 0;
	ft_memdel((void**)&e->line);
	init_tab_map(&e->map);
	while (++height < e->map.height && e->sw == 1)
	{
		while (e->map.tab_map[++width])
		{
			if (e->map.tab_map[height][width] == 'X')
				add_coordinates_player(&e->p2, (int[2]){height, width - 4});
			else if (e->map.tab_map[height][width] == 'O')
				add_coordinates_player(&e->p1, (int[2]){height, width - 4});
		}
		width = 3;
	}
}

void	get_map_size(t_fil *e)
{
	int		i;

	i = 8;
	sp_gnl(&e->line) == -1 ? error(-1) : 0;
	if (ft_strncmp(e->line, "Plateau ", 8))
		error(0);
	if ((e->map.height = ft_atoi(&e->line[i])) == 0)
		error(0);
	while (e->line[i] && e->line[i] != ' ')
		i++;
	if ((e->map.width = ft_atoi(&e->line[i])) == 0)
		error(0);
}
