/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 14:39:22 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/26 16:01:01 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define X 1280
# define Y 720

# include <libft.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

typedef struct		s_graph
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				height;
	int				width;
}					t_graph;

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
	int				parser[2];
	t_graph			gra;
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
int					result(t_fil *e);
void				piece_reset(t_fil *e);
void				clean_tab_piece(t_piece *piece);
void				reset_all(t_fil *e);
void				init_tab_piece(t_piece *piece);
void				init_tab_map(t_map *map);
void				clean_tab_map(t_map *map);
void				check_around(t_map *map, t_frame *p, int height, int width);
int					check_place(t_fil *e, int height, int width);
int					sp_gnl(char **line);
void				witch_way(t_fil *e);

#endif
