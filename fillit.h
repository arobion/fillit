/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 09:45:29 by arobion           #+#    #+#             */
/*   Updated: 2017/11/19 12:00:01 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 21

typedef struct		s_point
{
	int		x;
	int		y;
	char	value;
}					t_point;

typedef struct		s_tetri
{
	t_point		tab[4];
	t_tetri		*next;
}					t_tetri;

#endif
