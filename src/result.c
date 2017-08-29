/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 20:26:02 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/29 13:15:12 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	print_result(t_fil *e, int height, int width, int end)
{
	char	*str_height;
	char	*str_width;

	clean_piece(&e->piece);
	clean_tab_map(&e->map);
	if (end == 1)
		clean_frame_list(e);
	str_height = ft_itoa(height);
	ft_putstr(str_height);
	ft_memdel((void **)&str_height);
	ft_putstr(" ");
	str_width = ft_itoa(width);
	ft_putstr(str_width);
	ft_memdel((void **)&str_width);
	ft_putstr("\n");
}

// void	bresenham(int start[2], int end[2], t_fil *e)
// {
// 	e->bres.dx = abs(end[0] - start[0]);
// 	e->bres.dy = abs(end[1] - start[1]);
// 	e->bres.sx = start[0] < end[0] ? 1 : -1;
// 	e->bres.sy = start[1] < end[1] ? 1 : -1;
// 	e->bres.err = (e->bres.dx > e->bres.dy ? e->bres.dx : -e->bres.dy) / 2;
// 	while (1)
// 	{
// 		if (start[0] < e->map.width && start[0] >= 0 &&
// 			start[1] < e->map.height && start[1] >= 0)
// 			add_coordinates_bres(&e->bres, (int[2]){start[0], start[1]}));
// 		if (start[0] == end[0] && start[1] == end[1])
// 			break ;
// 		e->bres.err2 = e->bres.err;
// 		if (e->bres.err2 > -e->bres.dx)
// 		{
// 			e->bres.err -= e->bres.dy;
// 			start[0] += se->bres.x;
// 		}
// 		if (e->bres.err2 < e->bres.dy)
// 		{
// 			e->bres.err += e->bres.dx;
// 			start[1] += e->bres.sy;
// 		}
// 	}
// }

int		result(t_fil *e)
{
	if (!(parser(e, e->map.height / 2, e->map.width / 2)))
		return (0);
	print_result(e, 0, 0, 1);
	return (1);
}
