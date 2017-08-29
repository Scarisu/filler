/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:38:43 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/23 08:27:11 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*ft_strjoin_clean_gnl(char **s1, char *s2)
{
	char	*str;

	str = ft_strjoin(*s1, s2);
	ft_strdel(s1);
	*s1 = ft_strdup(str);
	ft_strdel(&str);
	return (*s1);
}

static int	read_line(t_line **list, char **line, int fd)
{
	int		i;
	int		ret;

	i = 0;
	ret = BUFF_SIZE;
	while (!(ft_strchr(*line, '\n')) && ret == BUFF_SIZE)
	{
		if ((*list)->tmp && ((*list)->tmp)[0] != '\0')
		{
			ft_strcpy((*list)->buff, (*list)->tmp);
			ft_strdel(&((*list)->tmp));
		}
		else if ((ret = read(fd, (*list)->buff, BUFF_SIZE)) < 1)
			if (ft_strlen(*line) == 0 || ret == -1)
				return (ret);
		((*list)->buff)[ret] = '\0';
		*line = ft_strjoin_clean_gnl(line, (char *)(*list)->buff);
	}
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	if (((*line)[i]))
		(*list)->tmp = ft_strsub(*line, i + 1, ft_strlen(*line) - i);
	while ((*line)[i])
		(*line)[i++] = '\0';
	return (1);
}

static int	init_struct(t_line **begin, t_line **list, int fd)
{
	*list = *begin;
	while (*list && fd != (*list)->fd)
		*list = (*list)->next;
	if (!(*list))
	{
		if (!(*list = (t_line *)malloc(sizeof(t_line))))
			return (-1);
		(*list)->fd = fd;
		(*list)->buff[BUFF_SIZE] = '\0';
		(*list)->tmp = NULL;
		(*list)->next = *begin;
		*begin = *list;
	}
	return (1);
}

static void	clear_struct(t_line **begin, t_line *list)
{
	t_line	*tmp;

	tmp = *begin;
	while (tmp && tmp->next && tmp->next != list)
		tmp = tmp->next;
	if (list != *begin)
		tmp->next = tmp->next->next;
	if (list == *begin)
		*begin = (*begin)->next;
	free(list);
}

int			get_next_line(const int fd, char **line)
{
	static t_line	*begin;
	t_line			*list;
	int				ret;

	ret = 0;
	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (!line)
		return (-1);
	if (!(*line = ft_strnew(1)))
		return (-1);
	if (!init_struct(&begin, &list, fd))
		return (-1);
	if ((ret = read_line(&list, line, fd)) < 1)
		clear_struct(&begin, list);
	return (ret);
}
