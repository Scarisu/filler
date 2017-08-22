/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 14:39:22 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/22 18:16:54 by pbernier         ###   ########.fr       */
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

typedef struct		p_piece
{
	int				height;
	int				width;	
	int				**coor;
}

typedef struct		p_frame
{
	char			player;
	int				**frame_list;
	int				nb;
}					t_frame;

typedef struct		s_map
{
	int				height;
	int				width;
}					t_map;

typedef struct		s_fil
{
	char			*line;
	char			player;
	t_piece			data;
	t_frame			p1;
	t_frame			p2;
	t_map			map;
}					t_fil;

void				error(int i);

void				get_piece(t_fil *e);
void				add_coordinates(t_frame *p, int *coor);

void				first_play(t_fil *e);
void				get_info(t_fil *e, int first_play);
void				get_map_size(t_fil *e);

void				clean_all(t_fil *e);
void				init(t_fil *e);

#endif
