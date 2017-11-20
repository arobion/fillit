/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:27:29 by arobion           #+#    #+#             */
/*   Updated: 2017/11/20 11:47:05 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_l_verif(char *l)
{
	int		i;
	int		j;
	int		connect;

	j = 0;
	i = 0;
	connect = 0;
	if (l[20] != '\n' && l[20] != '\0')
		return (0);
	while (l[i] != '\0' && i < 20)
	{
		if (((i + 1) % 5 != 0) && l[i] == '\n')
			return (0);	
		if (l[i] != '#' && l[i] != '\n' && l[i] != '.')
			return (0);
		if (l[i] == '#')
		{
			if (l[i + 1] == '#' && (i + 1) < 20)
				connect++;
			if (l[i - 1] == '#' && (i - 1) >= 0)
				connect++;
			if (l[i + 5] == '#' && (i + 5) < 20)
				connect++;
			if (l[i - 5] == '#' && (i - 5) >= 0)
				connect++;
			j++;
		}
		i++;
	}
	if ((connect != 6 && connect != 8) || j != 4)
		return (0);
	return (1);
}

t_tetri		*ft_create_elem(void) 
{
	t_tetri *tmp;

	tmp = ft_memalloc(sizeof(t_tetri));
	if (tmp)
		tmp->next = NULL;
	return (tmp);
}

static t_tetri	*ft_tetri_list_pushback(t_tetri **begin_list)
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

t_tetri		*ft_tetri_value(char *l, int value, t_tetri *list)
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
			list->tab[j].value	= value + 'A';
			j++;
		}
		i++;
	}
	return (list);
}

static int	ft_copy(int fd, t_tetri **begin_list)
{
	char	*l;
	size_t	end;
	t_tetri	*list;
	int		value;

	value = 0;
	list = NULL;
	if (!(l = ft_strnew(BUFF_SIZE)))
		return (0);
	while ((end = read(fd, l, BUFF_SIZE)))
	{
		if (!(ft_l_verif(l)))
			return (0);
		if (!(list = ft_tetri_list_pushback(begin_list)))
			return (0);
		if (!(list = ft_tetri_value(l, value, list)))
			return (0);
		value++;
		if (end < 20)
			return (0);
	}
	if (l[0] == '\0')
		return (0);
	ft_strdel(&l);
	return (1);
}

static int	ft_read_file(char *str)
{	
	int		fd;
	t_tetri	*begin_list;

	begin_list = NULL;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (0);
	if (!(ft_copy(fd, &begin_list)))
		return (0);
/*	while (begin_list)
	{
	dprintf(1, "point1x = %d\npoint1y = %d\n", begin_list->tab[0].x, begin_list->tab[0].y);
	dprintf(1, "point2x = %d\npoint2y = %d\n", begin_list->tab[1].x, begin_list->tab[1].y);
	dprintf(1, "point3x = %d\npoint3y = %d\n", begin_list->tab[2].x, begin_list->tab[2].y);
	dprintf(1, "point4x = %d\npoint4y = %d\n", begin_list->tab[3].x, begin_list->tab[3].y);
	dprintf(1, "pointvalue = %c\n", begin_list->tab[0].value);
	dprintf(1, "\n\n");
	begin_list = begin_list->next;
	}
*/	return (1);
}

int		main(int argc, char **argv)
{
	char	*line;

	if (argc != 2)
		return (write(1, "usage: fillit target\n", 21));
	if (!(ft_read_file(argv[1])))
		return (write(1, "error\n", 6));
	return (0);
}