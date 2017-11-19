/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:27:29 by arobion           #+#    #+#             */
/*   Updated: 2017/11/19 18:36:00 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int	ft_l_verif(char *l)
{
	int		i;
	int		j;
	int		connect;

	j = 0;
	i = 0;
	connect = 0;
	if (l[20] != '\n')
		return (0);
	while (l[i] != '\0')
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
	if (connect != 6 || connect != 8 || j != 4)
		return (0);
	return (1);
}

t_tetri		ft_create_elem(void) 
{
	t_tetri *tmp;

	tmp = ft_memalloc(sizeof(t_tetri));
	if (tmp)
		tmp->next = NULL;
}

t_tetri		*ft_create_tetri(char *l, int value)
{
	t_tetri	*list;
	int		i;
	int		j;

	j = 0;
	i = 1;
	if (!(list = ft_create_elem()))
		return (NULL);
	while (l[i - 1] != '\0')
	{
		if (l[i - 1] == '#')
		{
			list->((tab[j])->x) = i % 5;
			list->((tab[j])->y) = i / 5 + 1;
			list->((tab[j])->value)	= value + 'A';
			j++;
		}
		i++;
	}
	return (list);
}

static int	ft_copy(int fd, char **save, char *tmp)
{
	char	*l;
	size_t	end;
	t_tetri	*list;
	int		value;

	value = 0;
	if (!(l = ft_strnew(BUFF_SIZE)))
		return (0);
	while ((end = read(fd, l, BUFF_SIZE) >= 20))
	{
		if (!(ft_l_verif(l)))
			return (NULL);
		list = ft_create_tetri(l, value);
		value++;
	}
	ft_strdel(&l);
	return (1);
}

static int	ft_display_file(int fd, char **line)
{
	char	*save;
	char	*tmp;

	save = NULL;
	if (!(ft_copy(fd, (char**)&save, tmp)))
		return (0);
	if (!(*line = ft_strnew(ft_strlen_p(save))))
		return (0);
	ft_strncpy(*line, save, ft_strlen_p(save));
	ft_strdel(&save);
	ft_strdel(&tmp);
	return (1);
}

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;

	if (argc != 2)
		return (write(1, "usage: fillit target\n", 21));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (write(1, "error\n", 6));
	if (!(ft_display_file(fd, &line)))
		return (write(1, "error\n", 6));
	ft_putchar(line);
	return (0);
}
