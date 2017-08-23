/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 05:53:34 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/23 06:00:19 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int		main(void)
{
	int		fd;
	char	*line;

	fd = open("bongi", O_WRONLY);
	while ((get_next_line(0, &line)))
	{
		ft_putendl_fd(line, fd);
	}
	return (0);
}
