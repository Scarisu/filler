/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 14:38:25 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/22 21:49:36 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	whith_player(t_fil *e)
{
	get_next_line(1, &e->line) == -1 ? error(-1) : 0;
	if (e->line[6] == '1')
		e->player = 'o';
	else if (e->line[6] == '2')
		e->player = 'x';
	else
		error(0);
	free(e->line);
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
	whith_player(&e);
	init(&e);
	while (!e.line || e.line[0] != '=')
	{
		if (sw == 0)
			get_next_line(1, &e.line) == -1 ? error(-1) : 0;
		if (e.line[0] != '=' && e.line[0] != 'P')
			error(0);
		if (e.line[0] != '=')
		{
			free(e.line);
			get_info(&e, sw);
			get_piece(&e);
			print_result(&e);
		}
		sw = 0;
	}
	clean_all(&e);
	printf("TADA\n");
	while(1);
	return (0);
}
