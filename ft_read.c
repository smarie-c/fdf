/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 14:28:19 by smarie-c          #+#    #+#             */
/*   Updated: 2016/08/22 14:28:21 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_fill_point(char *line, t_data *data, int l)
{
	int		c;
	int		color;

	c = 0;
	while (c < data->nb_col)
	{
		if (!(data->map[l][c] = (t_vector *)ft_memalloc(sizeof(t_vector))))
			ft_free_data(data);
		(data->map[l][c])->x = c - (data->nb_col / 2);
		(data->map[l][c])->y = l - (data->nb_line / 2);
		(data->map[l][c])->z = ft_getn_number(line, c);
		(data->map[l][c])->a = c - (data->nb_col / 2);
		(data->map[l][c])->b = l - (data->nb_line / 2);
		(data->map[l][c])->c = (data->map[l][c])->z;
		(data->map[l][c])->w = 1;
		color = 0xff00 * ((data->map[l][c])->z + 1) * 10;
		if (color < 0)
			(data->map[l][c])->color =
				(0xCCCC / ((data->map[l][c])->z + 1) * -5);
		else
			(data->map[l][c])->color = color;
		c++;
	}
	data->map[l][c] = NULL;
}

static void		fill_map(t_data *data, char *file)
{
	int		fd;
	char	*line;
	int		l;

	fd = ft_open(data, file);
	l = 0;
	if (!(data->map = (t_vector ***)ft_memalloc(sizeof(t_vector **)
		* (data->nb_line + 1))))
		ft_free_data(data);
	while (get_next_line(fd, &line) > 0)
	{
		if (!(data->map[l] = (t_vector **)ft_memalloc(sizeof(t_vector *)
			* (data->nb_col + 1))))
			ft_free_data(data);
		ft_fill_point(line, data, l);
		++l;
		ft_strdel(&line);
	}
	data->map[l] = NULL;
	close(fd);
}

void			read_object(char *file, t_data *data)
{
	int		fd;
	char	*line;

	fd = ft_open(data, file);
	data->nb_line = 0;
	data->nb_col = -1;
	while (get_next_line(fd, &line) > 0)
	{
		ft_isnum_or_space(data, line, fd);
		data->nb_col = ft_check_line(line, fd);
		++(data->nb_line);
		ft_strdel(&line);
	}
	close(fd);
	if (data->nb_line <= 0 || data->nb_col <= 0)
	{
		ft_putendl_fd("WRONG MAP {file is incomplete}!", 2);
		ft_free_data(data);
	}
	fill_map(data, file);
}
