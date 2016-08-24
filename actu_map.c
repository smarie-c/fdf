/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actu_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 13:16:39 by smarie-c          #+#    #+#             */
/*   Updated: 2016/08/24 13:16:39 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		save_value(t_vector *v)
{
	v->x = v->a;
	v->y = v->b;
	v->z = v->c;
}

void			actu_map(t_data *data)
{
	int			i;
	int			j;
	t_matrix	tmp;

	m4_identity(&tmp);
	m4_mul_m4(&tmp, &tmp, &(data->scale));
	m4_mul_m4(&tmp, &tmp, &(data->rotz));
	m4_mul_m4(&tmp, &tmp, &(data->rotx));
	m4_mul_m4(&tmp, &tmp, &(data->roty));
	m4_mul_m4(&tmp, &tmp, &(data->translate));
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			save_value(data->map[i][j]);
			m4_mul_v4(&tmp, data->map[i][j]);
			j++;
		}
		i++;
	}
	ft_quadrilage(data);
}
