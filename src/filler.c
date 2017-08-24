/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 14:38:25 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/24 20:04:06 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	which_player(t_fil *e)
{
	get_next_line(0, &e->line) == -1 ? error(-1) : 0;
	if (e->line[10] == '1')
		e->player = 'o';
	else if (e->line[10] == '2')
		e->player = 'x';
	else
		error(0);
	ft_memdel((void**)&e->line);
}

void	error(int i)
{
	(i == -1) ? ft_putstr("Malloc error\n") : 0;
	(i == 0) ? ft_putstr("filler_vm: error on input\n") : 0;
	exit(-1);
}

int		main(void)
{
	int		sw;
	t_fil	e;

	sw = 1;
	which_player(&e);
	init(&e);
	while (1)
	{
		if (sw == 0)
			get_next_line(0, &e.line) == -1 ? error(-1) : 0;
		ft_memdel((void**)&e.line);
		get_info(&e);
		get_piece(&e);
		result(&e);
		sw = 0;

	}
//	printf("TADA\n");
//	while (1);
	return (0);
}
