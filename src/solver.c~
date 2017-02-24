/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:29:36 by rpatillo          #+#    #+#             */
/*   Updated: 2016/04/25 15:30:01 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int			ft_recursolve(t_env *e, int num, int size)
{
	int		x;
	int		y;
	int		min_map;

	if (num >= e->blocknbr)
		return (1);
	min_map = ft_sqrt(e);
	y = -1;
	while (++y < (size - ft_sizetetri_l(e, num) + 1))
	{
		x = -1;
		while (++x < (size - ft_sizetetri_h(e, num) + 1))
		{
			if (ft_putleft(e, num, x, y))
			{
				if (ft_recursolve(e, num + 1, size))
					return (1);
				else
					ft_rempiece(e, num, x, y);
			}
		}
	}
	return (0);
}

int			ft_solve(t_env *e)
{
	int		size;

	size = ft_sqrt(e);
	ft_place(e, size);
	while (!ft_recursolve(e, 0, size))
	{
		size++;
		ft_place(e, size);
	}
	return (0);
}
