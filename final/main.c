/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:27:29 by arobion           #+#    #+#             */
/*   Updated: 2017/11/22 11:29:46 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		i;
	char	**map;
	t_tetri *begin_list;

	begin_list = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: fillit target\n");
		return (0);
	}
	if (!(ft_read_file(argv[1], &begin_list)))
	{
		ft_putstr("error\n");
		return (0);
	}
	i = ft_count_size_list(begin_list);
	if (!(map = ft_create_map(i)))
		return (0);
	ft_solver(map, begin_list);
	ft_clear_list(&begin_list);
	return (0);
}
