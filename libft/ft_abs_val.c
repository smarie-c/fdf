/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_val.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 16:56:39 by smarie-c          #+#    #+#             */
/*   Updated: 2014/03/21 21:01:29 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_val_abs(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}
