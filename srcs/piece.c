/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 18:19:45 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/30 20:17:19 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	piece_info(t_fil *e)
{
	int		i;

	i = 6;
	sp_gnl(&e->line) == -1 ? error(-1) : 0;
	if (ft_strncmp(e->line, "Piece ", 6))
		error(0);
	if ((e->piece.height = ft_atoi(&e->line[i])) == 0 ||
			e->piece.height > e->map.height)
		error(0);
	while (e->line[i] && e->line[i] != ' ')
		i++;
	if ((e->piece.width = ft_atoi(&e->line[i])) == 0 ||
		e->piece.width > e->map.width)
		error(0);
	ft_memdel((void**)&e->line);
}

void	piece_coor(t_piece *piece, int sw)
{
	int	i;
	int	height;
	int	width;

	i = 0;
	height = -1;
	if (sw == 1 && !(piece->coor = (int **)malloc(sizeof(int *) * piece->size)))
		error(-1);
	while (++height < piece->height)
	{
		width = -1;
		while (++width < piece->width)
			if (piece->tab_piece[height][width] == '*')
			{
				piece->size += (sw == 0) ? 1 : 0;
				if (sw == 1)
				{
					if (!(piece->coor[i] = (int *)malloc(sizeof(int) * 2)))
						error(-1);
					ft_memcpy(piece->coor[i++],
						((int[2]){height, width}), sizeof(int[2]));
				}
			}
	}
	(sw == 0) ? piece_coor(piece, 1) : 0;
}

void	get_piece(t_fil *e)
{
	piece_info(e);
	init_tab_piece(&e->piece);
	piece_coor(&e->piece, 0);
	clean_tab_piece(&e->piece);
}
