/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 13:12:25 by smarie-c          #+#    #+#             */
/*   Updated: 2016/08/24 13:12:28 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	up_c_scale(t_data *data)
{
	data->c_scale += data->s_scale;
}

void	down_c_scale(t_data *data)
{
	data->c_scale -= data->s_scale;
}

void	up_cz_scale(t_data *data)
{
	data->cz_scale += .1;
}

void	down_cz_scale(t_data *data)
{
	data->cz_scale -= .1;
}
