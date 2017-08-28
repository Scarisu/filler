/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 20:26:02 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/28 16:12:10 by pbernier         ###   ########.fr       */
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

int		parser(t_fil *e)
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
				clean_piece(&e->piece);
				clean_frame_list(e);
				clean_tab_map(&e->map);
				print_result(height, width);
				return (0);
			}
	}
	return (1);
}

int		result(t_fil *e)
{
	if (!(parser(e)))
		return (0);
	clean_piece(&e->piece);
	clean_frame_list(e);
	clean_tab_map(&e->map);
	print_result(0, 0);
	return (1);
}
