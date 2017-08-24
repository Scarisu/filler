/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 00:30:13 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/18 12:05:35 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *ptr, size_t size)
{
	void *new;

	if (!(new = ft_memalloc(size)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(new, ptr, size);
		ft_memdel(&ptr);
	}
	return (new);
}
