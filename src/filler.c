/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 14:38:25 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/21 18:59:38 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	error(int i)
{
	(i == -1) ? ft_putstr("Malloc error\n") : 0;
	(i == 0) ? ft_putstr("filler_vm: error on input\n") : 0;
	exit(0);
}

void	clean_all(t_fil *e)
{
	printf("%d - %d\n", e->p1.nb, e->p2.nb);
	while (--e->p1.nb)
	{
		printf("p1 [%d - %d]\n", (e->p1.frame_list[e->p1.nb])[0],
								(e->p1.frame_list[e->p1.nb])[1]);
		free(e->p1.frame_list[e->p1.nb]);
	}
	printf("ho ho\n");
	while (--e->p2.nb)
	{
		printf("p2 [%d - %d]\n", (e->p2.frame_list[e->p2.nb])[0],
								(e->p2.frame_list[e->p2.nb])[1]);
		free(e->p2.frame_list[e->p2.nb--]);
	}
	free(e->p1.frame_list);
	free(e->p2.frame_list);
}


void	init_p_frame(t_fil *e)
{
	int		max_poss;

	max_poss = e->map.height * e->map.width;
	if (!(e->p1.frame_list = (int **)malloc(sizeof(int*) * max_poss)))
		error(-1);
	if (!(e->p2.frame_list = (int **)malloc(sizeof(int*) * max_poss)))
		error(-1);
	e->p1.nb = 0;
	e->p2.nb = 0;
}

int		main(void)
{
	char	*line;
	t_fil	e;

	get_next_line(1, &line) == -1 ? error(-1) : 0;
	e.player = (line[6] == '1') ? 'o' : 'x';
	free(line);
	get_map(&e.map);
	init_p_frame(&e);
	get_info(&e);

	clean_all(&e);
	return (0);
}
