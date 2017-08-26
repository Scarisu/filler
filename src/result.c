/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 20:26:02 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/26 16:40:53 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	print_result(int height, int width)
{
	char	*str_height;
	char	*str_width;

	str_height = ft_itoa(height);
	ft_putstr(str_height);
	ft_memdel((void **)&str_height);
	ft_putstr(" ");
	str_width = ft_itoa(width);
	ft_putstr(str_width);
	ft_memdel((void **)&str_width);
	ft_putstr("\n");
}

void	witch_way(t_fil *e)
{
	if ((e->p1.frame_list[0]) && (e->p2.frame_list[0]))
	{
		if (e->player == 'o')
			if (e->p1.frame_list[0][0] < e->p2.frame_list[0][0])
				e->parser[0] = -1;
		if (e->player == 'x')
			if (e->p1.frame_list[0][0] > e->p2.frame_list[0][0])
				e->parser[0] = -1;
	}
	e->parser[1] = 1;
}

int		up(t_fil *e)
{
	int	height;
	int	width;

	height = -1;
	while (++height != e->map.height)
	{
		width = -1;
		while (++width != e->map.width)
			if (!check_place(e, height, width))
			{
				reset_all(e);
				print_result(height, width);
				return (0);
			}
	}
	return (1);
}

int		down(t_fil *e)
{
	int	height;
	int	width;

	height = e->map.height;
	while (--height >= 0)
	{
		width = e->map.width;
		while (--width >= 0)
			if (!check_place(e, height, width))
			{
				reset_all(e);
				print_result(height, width);
				return (0);
			}
	}
	return (1);
}

int		result(t_fil *e)
{
	if (e->parser[0] == 1)
		if (!(up(e)))
			return (0);
	if (e->parser[0] == -1)
		if (!(down(e)))
			return (0);
	reset_all(e);
	clean_all(e);
	print_result(0, 0);
	return (1);
}
