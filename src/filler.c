/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 14:38:25 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/24 14:50:29 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	sp_gnl(char **line, int size)
{
	int		ret;
	char	buff[1];

	ret = -1;
	buff[0] = '\0';
	if (!(*line = (char *)malloc(sizeof(char) * (size + 1))))
		error(-1);
	(*line)[size] = '\0';
	if (size > 0)
	 	if ((ret = read(0, *line, size)) > 0 && (*line)[ret - 1] == '\n')
	 		(*line)[ret - 1] = '\0';
	if (size == 0)
	{
		while (buff[0] != '\n')
		{
			if ((ret = read(0, buff, 1)) == -1)
				return (ret);
			ft_strjoin_clean_char(line, buff[0]);
			++size;
		}
		(*line)[size - 1] = '\0';
		ret = size;
	}
	return (ret);
}

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
	(i == -1) ? ft_putstr_fd("Malloc error\n", 2) : 0;
	(i == 0) ? ft_putstr_fd("filler_vm: error on input\n", 2) : 0;
	(i == 1) ? ft_putstr_fd("Can't read file\n", 2) : 0;
	exit(-1);
}

int		main(void)
{
	int		sw;
	t_fil	e;

	sw = 1;

	//int k;
	// while(1)
	// {
	// 	printf("Ok\n");
	// 	k = sp_gnl(&e.line, 5);
	// 	printf("%d %s\n", k, e.line);
	// 	ft_memdel((void**)&e.line);
	// }

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
