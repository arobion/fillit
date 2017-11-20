/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:11:00 by arobion           #+#    #+#             */
/*   Updated: 2017/11/20 16:05:32 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_create_map(int nb)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = malloc(sizeof(char *) * nb + 1);
	while (i < nb)
	{
		map[i] = ft_strnew(nb);
		i++;
	}
	i = 0;
	while (i < nb)
	{
		while (j < nb)
		{
			map[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}	
	return (map);
}
