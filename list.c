/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:01:04 by arobion           #+#    #+#             */
/*   Updated: 2017/11/20 12:18:00 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
