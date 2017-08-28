/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 20:26:02 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/28 19:36:44 by pbernier         ###   ########.fr       */
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

// void	bresenham(int start[2], int end[2], int **bresenham)
// {
// 	dx = abs(end[0] - start[0]);
// 	dy = abs(end[1] - start[1]);
// 	sx = start[0] < end[0] ? 1 : -1;
// 	sy = start[1] < end[1] ? 1 : -1;
// 	err = (dx > dy ? dx : -dy) / 2;
// 	while (1)
// 	{
// 		if (start[0] < X && start[0] >= 0 && start[1] < Y && start[1] >= 0)
// 			conv_img(st[0], st[1], e);
// 		if (start[0] == end[0] && start[1] == end[1])
// 			break ;
// 		e2 = err;
// 		if (e2 > -dx)
// 		{
// 			err -= dy;
// 			start[0] += sx;
// 		}
// 		if (e2 < dy)
// 		{
// 			err += dx;
// 			start[1] += sy;
// 		}
// 	}
// }

// if (!check_place(e, height, width))
// {
// 	print_result(e, height, width, 0);
// 	return (0);
// }

int		parser(t_fil *e, int y, int x)
{
	int	height;
	int	width;
	int cercle;
	int	line;

	(void)e;
	cercle = 0;
	line = 0;
	while (cercle < 3)
	{
		height = y - cercle;
		printf("\ncercle\n");
		printf("[%d<%d]..\n", height, y + cercle + line);
		while (height <= y + cercle + line)
		{
			width = x - cercle;
			printf("line\n");
			while (width < x + cercle + line)
			{
				printf("[%d][%d]\n", height, width);
				++width;
			}
			++height;
		}
		++cercle;
		++line;
	}
	return (1);
}

int		result(t_fil *e)
{
	if (!(parser(e, 0, 0)))
		return (0);
	printf("DONE\n");
	while(1);
	print_result(e, 0, 0, 1);
	return (1);
}
