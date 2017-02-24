/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 14:18:40 by rpatillo          #+#    #+#             */
/*   Updated: 2016/04/25 15:38:43 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "fillit.h"

typedef struct	s_env
{
	int			blocknbr;
	char		**tab;
	char		**solu;
	char		***split;
	int			x;
	int			y;
	int			th;
	int			tl;
	int			size;
	char		*point;
	char		*map;
	int			s_i;
	int			s_j;
	int			s_k;
	int			s_l;
}				t_env;

#endif
