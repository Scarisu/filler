/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 14:39:22 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/21 18:36:17 by pbernier         ###   ########.fr       */
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

typedef struct		p_frame
{
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
	char			player;
	t_frame			p1;
	t_frame			p2;
	t_map			map;
}					t_fil;

void				error(int i);
void				add_coordinates(t_frame *p, int *coor);
void				get_info(t_fil *e);
void				get_map(t_map *map);

#endif
