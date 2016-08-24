/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oddprev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <smarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 12:47:41 by smarie-c          #+#    #+#             */
/*   Updated: 2014/03/16 13:03:39 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_oddprev(char const *s, int i, char c)
{
	int		nb;

	nb = 0;
	while (i >= 0 && s[i] == c)
	{
		nb++;
		i--;
	}
	return (nb % 2);
}