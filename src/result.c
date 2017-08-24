/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 20:26:02 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/24 16:05:06 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void		print_result(int height, int width)
{
	printf("%d %d\n", height, width);
}

void	result(t_fil *e)
{
	int	height;
	int	width;

	height = -1;
	while (++height < e->map.height)
	{
		width = -1;
		while (++width < e->map.width)
			if (!check_place(e, height, width))
			{
				reset_all(e);
				print_result(height, width);
				return ;
			}
	}
	reset_all(e);
	clean_all(e);
	print_result(0, 0);
}
