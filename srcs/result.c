/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 20:26:02 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/29 13:50:33 by pbernier         ###   ########.fr       */
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

int		result(t_fil *e)
{
	if (!(parser(e, e->map.height / 2, e->map.width / 2)))
		return (0);
	print_result(e, 0, 0, 1);
	return (1);
}
