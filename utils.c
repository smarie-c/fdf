/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 14:29:07 by smarie-c          #+#    #+#             */
/*   Updated: 2016/08/22 14:29:07 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	dmin(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

static double	dtoi(int n)
{
	double	d;

	d = (double)n;
	return (d);
}

void			init_var(t_data *data)
{
	data->rot_x = -1.250;
	data->rot_y = -0.05;
	data->rot_z = 0.75;
	data->c_scale = 1.2 * dmin(dtoi(WIDTH) / dtoi(data->nb_line)
		, dtoi(HEIGHT) / dtoi(data->nb_col));
	data->s_scale = data->c_scale / 20.0;
	data->cz_scale = -.4;
	data->posx = (WIDTH / 2);
	data->posy = (HEIGHT / 2);
	data->posz = 1.0;
}

void			init_matrix(t_data *data)
{
	m4_translate(&(data->translate), data->posx, data->posy, data->posz);
	m4_scale(&(data->scale), data->c_scale, data->c_scale, data->cz_scale);
	m4_rot_x(&(data->rotx), data->rot_x);
	m4_rot_y(&(data->roty), data->rot_y);
	m4_rot_z(&(data->rotz), data->rot_z);
}

void			ft_free_data(t_data *data)
{
	int		l;
	int		c;

	if (data->map)
	{
		l = 0;
		while (data->map[l])
		{
			c = 0;
			while (data->map[l][c])
			{
				free(data->map[l][c]);
				++c;
			}
			free(data->map[l]);
			++l;
		}
		free(data->map);
	}
	free(data);
	ft_get_key(-1);
	exit(0);
}
