/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 18:43:56 by acabaill          #+#    #+#             */
/*   Updated: 2016/04/25 15:14:30 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int			ft_error(int x)
{
	if (x == 1)
		ft_putendl("error");
	if (x == 2)
		ft_putendl("error");
	exit(0);
}

int			ft_sizetetri_l(t_env *e, int num)
{
	int		i;
	int		j;
	int		tmp_j;

	e->tl = 0;
	i = 0;
	while (e->split[num][i] != '\0')
	{
		tmp_j = 0;
		j = 0;
		while (e->split[num][i][j] != '\0')
		{
			if (ft_isalpha(e->split[num][i][j]))
				tmp_j = 1;
			j++;
		}
		if (tmp_j == 1)
			e->tl++;
		i++;
	}
	return (e->tl);
}

int			ft_sizetetri_h(t_env *e, int num)
{
	int		i;
	int		j;
	int		tmp_i;

	e->th = 0;
	i = 0;
	j = 0;
	while (j < 4)
	{
		tmp_i = 0;
		i = 0;
		while (i < 4)
		{
			if (ft_isalpha(e->split[num][i][j]))
				tmp_i = 1;
			i++;
		}
		if (tmp_i == 1)
			e->th++;
		j++;
	}
	return (e->th);
}
