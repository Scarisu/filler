/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 02:11:44 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/30 20:15:26 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (little[0] == '\0')
		return (char*)(big);
	while (big[i] != '\0')
	{
		j = i;
		k = 0;
		while (big[j] == little[k])
		{
			j++;
			k++;
			if (little[k] == '\0')
				return (char*)(&big[i]);
		}
		i++;
	}
	return (NULL);
}
