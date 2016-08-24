/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 13:12:49 by smarie-c          #+#    #+#             */
/*   Updated: 2016/08/24 13:12:52 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	right_event(t_data *data)
{
	data->posx += 5;
}

void	left_event(t_data *data)
{
	data->posx -= 5;
}

void	down_event(t_data *data)
{
	data->posy += 5;
}

void	up_event(t_data *data)
{
	data->posy -= 5;
}
