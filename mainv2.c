/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:27:29 by arobion           #+#    #+#             */
/*   Updated: 2017/11/19 19:48:58 by arobion          ###   ########.fr       */
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
	while (l[i] != '\0' && i <= 20)
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
	if (connect != 6 && connect != 8 && j != 4)
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

	tmp = *begin_list;					//peut etre une erreur de next 
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = ft_create_elem()))
			return (NULL);
	}
	else
		*begin_list = ft_create_elem();
	return (tmp);
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
			list->tab[j].x = i % 5;				// peut etre necessaire de malloc le tab de structure ??
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
	while ((end = read(fd, l, BUFF_SIZE) >= 20))			// peut etre une source d'erreur dans la verification de la chaine avec end
	{
		if (!(ft_l_verif(l)))
			return (0);
		if (!(list = ft_tetri_list_pushback(begin_list)))
			return (0);
		dprintf(1, "ici\n");
		if (!(list = ft_tetri_value(l, value, list)))
			return (0);
		value++;
	}
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
	return (1);
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
