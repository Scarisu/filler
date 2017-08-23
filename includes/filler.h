/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 14:39:22 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/23 03:34:23 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

typedef struct		s_piece
{
	int				height;
	int				width;
	int				size;
	int				**coor;
	char			**tab_piece;
}					t_piece;

typedef struct		s_frame
{
	char			player;
	int				**frame_list;
	int				nb;
}					t_frame;

typedef struct		s_map
{
	int				height;
	int				width;
	char			**tab_map;
}					t_map;

typedef struct		s_fil
{
	char			*line;
	char			player;
	int				result[2];
	t_piece			piece;
	t_frame			p1;
	t_frame			p2;
	t_map			map;
}					t_fil;

void				error(int i);
void				get_piece(t_fil *e);
void				add_coordinates(t_frame *p, int *coor);
void				first_play(t_fil *e);
void				get_info(t_fil *e);
void				get_map_size(t_fil *e);
void				clean_all(t_fil *e);
void				init(t_fil *e);
void				print_result(t_fil *e);
void				piece_reset(t_fil *e);
void				clean_tab_piece(t_piece *piece);
void				reset_all(t_fil *e);
void				init_tab_piece(t_piece *piece);
void				init_tab_map(t_map *map);
void				clean_tab_map(t_map *map);
void				check_around(t_map *map, t_frame *p, int height, int width);

#endif
