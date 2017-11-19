/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:27:29 by arobion           #+#    #+#             */
/*   Updated: 2017/11/19 12:00:04 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

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

	i = 0;
	if (!(list = ft_create_elem()))
		return (NULL);
	while (l[i] != '\0')
	{
		if (l[i] == '#')


	

	

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
		while (*l++)
			if (*l != '#' && *l != '.' && *l != '\n')
				return (0);
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

