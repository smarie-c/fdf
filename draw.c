/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 14:28:08 by smarie-c          #+#    #+#             */
/*   Updated: 2016/08/22 14:28:10 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel_to_screen(t_data *e, int x, int y, int color)
{
	int		*ptr;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	ptr = (int *)(e->str + x * (e->bpp >> 3) + y * e->sl);
	*ptr = color;
}
