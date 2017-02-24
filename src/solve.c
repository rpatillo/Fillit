/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 12:17:08 by rpatillo          #+#    #+#             */
/*   Updated: 2016/04/25 15:30:06 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int			ft_place(t_env *e, int size)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	if (!(e->solu = (char**)malloc(sizeof(char *) * size + 1)))
		ft_error(2);
	while (i < size)
	{
		e->solu[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			e->solu[i][j] = '.';
			j++;
		}
		i++;
	}
	e->solu[i] = NULL;
	return (0);
}

int			ft_putleft(t_env *e, int num, int x, int y)
{
	int		i;
	int		j;

	j = 0;
	while (j < ft_sizetetri_l(e, num))
	{
		i = 0;
		while (i < ft_sizetetri_h(e, num))
		{
			if (ft_isalpha(e->split[num][j][i]) && e->solu[y + j][x + i] != '.')
				return (0);
			i++;
		}
		j++;
	}
	ft_putpiece(e, num, x, y);
	return (1);
}

int			ft_rempiece(t_env *e, int num, int x, int y)
{
	int		i;
	int		j;

	j = 0;
	while (j < ft_sizetetri_l(e, num))
	{
		i = 0;
		while (i < ft_sizetetri_h(e, num))
		{
			if (ft_isalpha(e->split[num][j][i]))
				e->solu[y + j][x + i] = '.';
			i++;
		}
		j++;
	}
	return (0);
}

int			ft_putpiece(t_env *e, int num, int x, int y)
{
	int		i;
	int		j;

	j = 0;
	while (j < ft_sizetetri_l(e, num))
	{
		i = 0;
		while (i < ft_sizetetri_h(e, num))
		{
			if (ft_isalpha(e->split[num][j][i]))
				e->solu[y + j][x + i] = e->split[num][j][i];
			i++;
		}
		j++;
	}
	return (0);
}

int			ft_sqrt(t_env *e)
{
	int		i;

	i = 0;
	while (e->blocknbr * 4 > i * i)
		i++;
	if (i >= 4)
		return (i);
	return (3);
}
