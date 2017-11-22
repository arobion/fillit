/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:11:00 by arobion           #+#    #+#             */
/*   Updated: 2017/11/22 11:38:50 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_size_list(t_tetri *begin_list)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	i *= 4;
	while ((j * j) < i)
		j++;
	j++;
	if (j < 4)
		j = 4;
	return (j);
}

char	**ft_create_map(int nb)
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

void	ft_putmap(char **map, int c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (map)
	{
		while (i <= c)
		{
			while (j <= c)
			{
				ft_putchar(map[i][j]);
				j++;
			}
			j = 0;
			i++;
			ft_putchar('\n');
		}
	}
}
