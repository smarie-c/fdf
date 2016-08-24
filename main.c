/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 14:49:09 by smarie-c          #+#    #+#             */
/*   Updated: 2016/08/22 14:49:10 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf(t_data *data)
{
	init_var(data);
	init_matrix(data);
	ft_clear_with_color(data, FONT_COLOR);
	actu_map(data);
	mlx_put_image_to_window(data->core, data->win, data->img, 0, 0);
	mlx_expose_hook(data->win, &ft_event_expose, data);
	mlx_hook(data->win, 2, 3, &ft_event, data);
	mlx_loop(data->core);
}

void			ft_clear_with_color(t_data *data, int color)
{
	int		i;

	i = 0;
	while (i < HEIGHT * data->sl)
	{
		*((int*)(data->str + i)) = color;
		i += 4;
	}
}

int				main(int ac, char **av)
{
	t_data		*data;
	t_key		**key_tab;

	if (ac != 2)
	{
		ft_putendl_fd("Usage: fdf <map>", 2);
		return (0);
	}
	if (!(data = ft_memalloc(sizeof(t_data))))
		return (0);
	if (!(key_tab = ft_get_key(0)))
		ft_free_data(data);
	read_object(av[1], data);
	if (!(data->core = mlx_init()))
		ft_free_data(data);
	if (!(data->win = mlx_new_window(data->core, WIDTH, HEIGHT, av[1])))
		ft_free_data(data);
	if (!(data->img = mlx_new_image(data->core, WIDTH, HEIGHT)))
		ft_free_data(data);
	if (!(data->str = mlx_get_data_addr(data->img,
		&(data->bpp), &(data->sl), &(data->endian))))
		ft_free_data(data);
	fdf(data);
	return (0);
}
