/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 14:27:45 by smarie-c          #+#    #+#             */
/*   Updated: 2016/08/22 14:27:48 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_draw_h(double derr, t_data *data, t_vector *p1, t_vector *p2)
{
	int		x;
	int		y;
	double	err;

	x = p1->x;
	y = p1->y;
	err = 0;
	while (x < p2->x)
	{
		ft_put_pixel_to_screen(data, x, y, p1->color);
		err += derr;
		if (err > 0.5)
		{
			y += (p1->y < p2->y) ? 1 : -1;
			err -= 1.0;
		}
		x++;
	}
}

static void		ft_draw_l(double derr, t_data *data, t_vector *p1, t_vector *p2)
{
	int		x;
	int		y;
	double	err;

	x = p1->x;
	y = p1->y;
	err = 0;
	while (y < p2->y)
	{
		ft_put_pixel_to_screen(data, x, y, p1->color);
		err += derr;
		if (err > 0.5)
		{
			x += (p1->x < p2->x) ? 1 : -1;
			err -= 1.0;
		}
		y++;
	}
}

static void		draw_line(t_vector *p1, t_vector *p2, t_data *data)
{
	double	dx;
	double	dy;

	dx = ABS(p2->x - p1->x);
	dy = ABS(p2->y - p1->y);
	if (dx > dy && (p1->x > p2->x))
		draw_line(p2, p1, data);
	else if (dx > dy)
		ft_draw_h(dy / dx, data, p1, p2);
	else if (p1->y > p2->y)
		draw_line(p2, p1, data);
	else
		ft_draw_l(dx / dy, data, p1, p2);
}

void			ft_quadrilage(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (i > 0)
				draw_line(data->map[i][j], data->map[i - 1][j], data);
			if (j > 0)
				draw_line(data->map[i][j], data->map[i][j - 1], data);
			j++;
		}
		i++;
	}
}
