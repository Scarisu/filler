/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 02:34:03 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/23 07:00:53 by pbernier         ###   ########.fr       */
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

void	clean_all(t_fil *e)
{
	ft_memdel((void**)&e->line);
	ft_memdel((void**)&e->p1.frame_list);
	ft_memdel((void**)&e->p2.frame_list);
}
