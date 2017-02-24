/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 13:48:32 by rpatillo          #+#    #+#             */
/*   Updated: 2016/04/25 15:12:18 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int			ft_movetetri(t_env *e)
{
	int		i;

	i = 0;
	while (e->split[i] != '\0')
	{
		ft_movetetri_sub(e->split[i], e);
		i++;
	}
	return (0);
}

int			ft_movetetri_sub(char **tab, t_env *e)
{
	int		i;
	int		j;

	e->th = 5;
	e->tl = 5;
	i = 0;
	while (tab[i] != '\0')
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] != '.' && e->th > i)
				e->th = i;
			if (tab[i][j] != '.' && e->tl > j)
				e->tl = j;
			j++;
		}
		i++;
	}
	ft_movetetri_sub2(tab, e);
	return (0);
}

int			ft_movetetri_sub2(char **tab, t_env *e)
{
	int		i;
	int		j;

	if (e->th == 0 && e->tl == 0)
		return (0);
	i = 0;
	while (tab[i] != '\0')
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] != '.')
			{
				tab[i - e->th][j - e->tl] = tab[i][j];
				tab[i][j] = '.';
			}
			j++;
		}
		i++;
	}
	return (0);
}
