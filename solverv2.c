/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:07:00 by arobion           #+#    #+#             */
/*   Updated: 2017/11/20 19:40:09 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_clear_tetri(t_point pos, char **map, t_tetri *list)
{
	int		i;

	i = 1;
	map[pos.y][pos.x] = '.';
	while (i < 4)
	{
		map[(pos.y + list->tab[i].y)][(pos.x + list->tab[i].x)] = '.';
		i++;
	}
	return (1);
}

static int	ft_put_tetri(t_point pos, int c, char **map, t_tetri *list)
{
	int		i;

	i = 1;
	if (map[pos.y][pos.x] != '.')
		return (0);
	while (i < 4)
	{
		if ((pos.x + list->tab[i].x) > c)
			return (0);
		if ((pos.y + list->tab[i].y) > c)
			return (0);
		if (map[(pos.y + list->tab[i].y)][(pos.x + list->tab[i].x)] != '.')
			return (0);
		i++;
	}
	map[pos.y][pos.x] = list->tab[0].value;
	i = 1;
	while (i < 4)
	{
		map[(pos.y + list->tab[i].y)][(pos.x + list->tab[i].x)] = list->tab[0].value;
		i++;
	}
	return (1);
}

static int	ft_backtrack(t_point pos, int c, char **map, t_tetri *begin_list)
{
	t_point	start;
	int		i;

	i = 0;
	start.x = 0;
	start.y = 0;
	if (begin_list == NULL)
		return (1);
	if (pos.y > c)
		return (0);
	if (pos.x > c)
	{
		pos.x = 0;
		pos.y += 1;
		return (ft_backtrack(pos, c, map, begin_list));
	}
	while (pos.y <= c)
	{
		if ((i = ft_put_tetri(pos, c, map, begin_list)) == 1)
		{
			if (ft_backtrack(start, c, map, begin_list->next) == 1)
				return (1);
		}
		if (i == 1)
		{
			ft_clear_tetri(pos, map, begin_list);
			i = 0;
		}
		pos.x += 1;
		if (pos.x > c)
		{
			pos.x = 0;
			pos.y += 1;
		}
	}
	return (0);
}

void	ft_solver(char **map, t_tetri *begin_list)
{
	t_point	pos;
	int		c;

	pos.x = 0;
	pos.y = 0;
	c = ft_strlen(*map);
	c--;
	c--;
	if (!(ft_backtrack(pos, c, map, begin_list)))
		{
			c++;
			ft_backtrack(pos, c, map, begin_list);
		}
	ft_puttab(map);
}
