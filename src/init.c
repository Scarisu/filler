/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 16:00:10 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/26 15:30:27 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	init_tab_map(t_map *map)
{
	int		height;

	height = -1;
	if (!(map->tab_map = (char **)malloc(sizeof(char *) * (map->height + 1))))
		error(-1);
	map->tab_map[map->height] = NULL;
	while (++height < map->height)
		sp_gnl(&map->tab_map[height]) == -1 ? error(-1) : 0;
}

void	init_tab_piece(t_piece *piece)
{
	int		height;

	height = -1;
	if (!(piece->tab_piece =
		(char **)malloc(sizeof(char *) * (piece->height + 1))))
		error(-1);
	piece->tab_piece[piece->height] = NULL;
	while (++height < piece->height)
		sp_gnl(&piece->tab_piece[height]) == -1 ? error(-1) : 0;
}

void	reset_all(t_fil *e)
{
	e->piece.height = 0;
	e->piece.width = 0;
	while (--e->piece.size >= 0)
		ft_memdel((void**)&e->piece.coor[e->piece.size]);
	e->piece.size = 0;
	ft_memdel((void**)&e->piece.coor);
	while (--e->p1.nb >= 0)
		ft_memdel((void**)&e->p1.frame_list[e->p1.nb]);
	e->p1.nb = 0;
	while (--e->p2.nb >= 0)
		ft_memdel((void**)&e->p2.frame_list[e->p2.nb]);
	e->p2.nb = 0;
	clean_tab_map(&e->map);
}

void	init_window()
{
	int		i;

	e->gra.height = ()
	e->gra.width = 
	e->gra.mlx = mlx_init();
	e->gra.win = mlx_new_window(e->gra.mlx, e, Y, "filler");
	e->gra.img = mlx_new_image(e->gra.mlx, X, Y);
	e->gra.data = mlx_get_data_addr(e->gra.img, &i, &i, &i);
}

void	init(t_fil *e)
{
	int		max_poss;

	get_map_size(e);
	init
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
