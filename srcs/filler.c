/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 14:38:25 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/29 15:17:58 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		sp_gnl(char **line)
{
	int		ret;
	int		size;
	char	buff[1];

	size = 0;
	buff[0] = '\0';
	if (!(*line = (char *)malloc(sizeof(char) * (size + 1))))
		error(-1);
	(*line)[size] = '\0';
	while (buff[0] != '\n')
	{
		if ((ret = read(0, buff, 1)) == -1)
			error(1);
		ft_strjoin_clean_char(line, buff[0]);
		++size;
	}
	(*line)[size - 1] = '\0';
	ret = size;
	return (ret);
}

void	which_player(t_fil *e)
{
	sp_gnl(&e->line) == -1 ? error(-1) : 0;
	if (ft_strncmp(e->line, "$$$ exec p", 9))
		error(0);
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
	int		ret;
	t_fil	e;

	ret = 0;
	which_player(&e);
	init(&e);
	while (ret == 0)
	{
		if (e.sw == 0)
			sp_gnl(&e.line) == -1 ? error(-1) : 0;
		ft_memdel((void**)&e.line);
		get_info(&e);
		get_piece(&e);
		ret = result(&e);
		e.sw = 0;
	}
	return (0);
}
