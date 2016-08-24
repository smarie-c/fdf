/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 14:28:59 by smarie-c          #+#    #+#             */
/*   Updated: 2016/08/22 14:28:59 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix		*m4_mul_m4(t_matrix *m, t_matrix *b, t_matrix *a)
{
	t_matrix	tmp;

	tmp.a = a->a * b->a + a->b * b->e + a->c * b->i + a->d * b->m;
	tmp.b = a->a * b->b + a->b * b->f + a->c * b->j + a->d * b->n;
	tmp.c = a->a * b->c + a->b * b->g + a->c * b->k + a->d * b->o;
	tmp.d = a->a * b->d + a->b * b->h + a->c * b->l + a->d * b->p;
	tmp.e = a->e * b->a + a->f * b->e + a->g * b->i + a->h * b->m;
	tmp.f = a->e * b->b + a->f * b->f + a->g * b->j + a->h * b->n;
	tmp.g = a->e * b->c + a->f * b->g + a->g * b->k + a->h * b->o;
	tmp.h = a->e * b->d + a->f * b->h + a->g * b->l + a->h * b->p;
	tmp.i = a->i * b->a + a->j * b->e + a->k * b->i + a->l * b->m;
	tmp.j = a->i * b->b + a->j * b->f + a->k * b->j + a->l * b->n;
	tmp.k = a->i * b->c + a->j * b->g + a->k * b->k + a->l * b->o;
	tmp.l = a->i * b->d + a->j * b->h + a->k * b->l + a->l * b->p;
	tmp.m = a->m * b->a + a->n * b->e + a->o * b->i + a->p * b->m;
	tmp.n = a->m * b->b + a->n * b->f + a->o * b->j + a->p * b->n;
	tmp.o = a->m * b->c + a->n * b->g + a->o * b->k + a->p * b->o;
	tmp.p = a->m * b->d + a->n * b->h + a->o * b->l + a->p * b->p;
	*m = tmp;
	return (m);
}

t_vector		*m4_mul_v4(t_matrix *m, t_vector *v)
{
	double		i;
	double		j;
	double		k;
	double		w;

	i = m->a * v->x + m->b * v->y + m->c * v->z + m->d;
	j = m->e * v->x + m->f * v->y + m->g * v->z + m->h;
	k = m->i * v->x + m->j * v->y + m->k * v->z + m->l;
	w = m->m * v->x + m->n * v->y + m->o * v->z + m->p;
	v->x = i;
	v->y = j;
	v->z = k;
	v->w = w;
	return (v);
}

void			m4_identity(t_matrix *m)
{
	ft_bzero(m, sizeof(t_matrix));
	m->a = 1;
	m->f = 1;
	m->k = 1;
	m->p = 1;
}

void			m4_translate(t_matrix *m, double i, double j, double k)
{
	m4_identity(m);
	m->d = i;
	m->h = j;
	m->l = k;
}

void			m4_scale(t_matrix *m, double nx, double ny, double nz)
{
	m4_identity(m);
	m->a = nx;
	m->f = ny;
	m->k = nz;
}
