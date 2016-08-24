/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 13:18:54 by smarie-c          #+#    #+#             */
/*   Updated: 2016/08/24 13:18:57 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_search_event(t_data *data, int keycode)
{
	int		i;
	t_key	**key_tab;

	if (!(key_tab = ft_get_key(1)))
		ft_free_data(data);
	i = 0;
	while (key_tab[i])
	{
		if (key_tab[i]->key == keycode)
			return (key_tab[i]->fct(data));
		++i;
	}
}

int				ft_event_expose(t_data *data)
{
	mlx_put_image_to_window(data->core, data->win, data->img, 0, 0);
	return (0);
}

int				ft_event(int keycode, t_data *data)
{
	ft_clear_with_color(data, FONT_COLOR);
	ft_search_event(data, keycode);
	init_matrix(data);
	actu_map(data);
	mlx_put_image_to_window(data->core, data->win, data->img, 0, 0);
	return (1);
}
