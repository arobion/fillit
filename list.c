/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:01:04 by arobion           #+#    #+#             */
/*   Updated: 2017/11/20 16:10:54 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_count_size_list(t_tetri *begin_list)
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

static void		ft_change_reper(t_tetri **list)
{
	int		i;
	t_point	save;

	save.x = (*list)->tab[0].x;
	save.y = (*list)->tab[0].y;
	(*list)->tab[0].x = 0;
	(*list)->tab[0].y = 0;
	i = 1;
	while (i < 4)
	{
		(*list)->tab[i].x -= save.x;
		(*list)->tab[i].y -= save.y;
		i++;
	}
}

t_tetri			*ft_tetri_value(char *l, int value, t_tetri *list)
{
	int		i;
	int		j;

	j = 0;
	i = 1;
	while (l[i - 1] != '\0')
	{
		if (l[i - 1] == '#')
		{
			list->tab[j].x = i % 5;
			list->tab[j].y = i / 5 + 1;
			list->tab[j].value = value + 'A';
			j++;
		}
		i++;
	}
	ft_change_reper(&list);
	return (list);
}

static t_tetri	*ft_create_elem(void)
{
	t_tetri *tmp;

	tmp = ft_memalloc(sizeof(t_tetri));
	if (tmp)
		tmp->next = NULL;
	return (tmp);
}

t_tetri			*ft_tetri_list_pushback(t_tetri **begin_list)
{
	t_tetri *tmp;

	tmp = *begin_list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = ft_create_elem()))
			return (NULL);
	}
	else
	{
		if (!(*begin_list = ft_create_elem()))
			return (NULL);
		return (*begin_list);
	}
	return (tmp->next);
}
