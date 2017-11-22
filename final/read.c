/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:59:32 by arobion           #+#    #+#             */
/*   Updated: 2017/11/22 12:27:52 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_check_connect(char *l, int i, int *j, int *connect)
{
	if (l[i + 1] == '#' && (i + 1) < 20)
		(*connect)++;
	if (l[i - 1] == '#' && (i - 1) >= 0)
		(*connect)++;
	if (l[i + 5] == '#' && (i + 5) < 20)
		(*connect)++;
	if (l[i - 5] == '#' && (i - 5) >= 0)
		(*connect)++;
	(*j)++;
}

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
			ft_check_connect(l, i, &j, &connect);
		i++;
	}
	if ((connect != 6 && connect != 8) || j != 4)
		return (0);
	return (1);
}

static int	ft_boucle(char *l, t_tetri **begin_list, t_tetri *list, int value)
{
	if (!(ft_l_verif(l)))
		return (0);
	if (!(list = ft_tetri_list_pushback(begin_list)))
		return (0);
	if (!(list = ft_tetri_value(l, value, list)))
		return (0);
	return (1);
}

static int	ft_copy(int fd, t_tetri **begin_list, int *fin)
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
		if (!(ft_boucle(l, begin_list, list, value)))
			return (0);
		value++;
		if (value > 26)
			return (0);
		if (end == 20)
			(*fin)++;
		if (end < 20)
			return (0);
	}
	if (l[0] == '\0')
		return (0);
	ft_strdel(&l);
	return (1);
}

int			ft_read_file(char *str, t_tetri **begin_list)
{
	int		fd;
	int		fin;

	fin = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (0);
	if (!(ft_copy(fd, begin_list, &fin)))
		return (0);
	if (fin != 1)
		return (0);
	return (1);
}
