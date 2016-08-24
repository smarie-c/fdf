/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rot_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 14:27:58 by smarie-c          #+#    #+#             */
/*   Updated: 2016/08/22 14:27:59 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	m4_rot_x(t_matrix *m, double angle)
{
	m4_identity(m);
	m->f = cos(angle);
	m->g = -sin(angle);
	m->j = sin(angle);
	m->k = cos(angle);
}

void	m4_rot_y(t_matrix *m, double angle)
{
	m4_identity(m);
	m->a = cos(angle);
	m->c = sin(angle);
	m->i = -sin(angle);
	m->k = cos(angle);
}

void	m4_rot_z(t_matrix *m, double angle)
{
	m4_identity(m);
	m->a = cos(angle);
	m->b = -sin(angle);
	m->e = sin(angle);
	m->f = cos(angle);
}
