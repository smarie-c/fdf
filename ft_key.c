/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 13:22:27 by smarie-c          #+#    #+#             */
/*   Updated: 2016/08/24 13:22:28 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_del_key(t_key ***key_tab)
{
	int		i;

	if (*key_tab)
	{
		i = 0;
		while ((*key_tab)[i])
		{
			free((*key_tab)[i]);
			++i;
		}
		free(*key_tab);
	}
}

static void		ft_addkey(t_key **key_tab, int key, t_fct fct)
{
	int		i;

	i = 0;
	if (!key_tab)
		return ;
	while (key_tab[i])
		++i;
	if (!(key_tab[i] = ft_memalloc(sizeof(t_key))))
		ft_del_key(&key_tab);
	key_tab[i]->key = key;
	key_tab[i]->fct = fct;
}

static void		ft_initkey(t_key ***key_tab)
{
	if (!(*key_tab = ft_memalloc(sizeof(t_key*) * (NB_KEY + 1))))
		return ;
	ft_addkey(*key_tab, KEY_ESC, &ft_free_data);
	ft_addkey(*key_tab, KEY_R, &init_var);
	ft_addkey(*key_tab, KEY_RIGHT, &right_event);
	ft_addkey(*key_tab, KEY_LEFT, &left_event);
	ft_addkey(*key_tab, KEY_DOWN, &down_event);
	ft_addkey(*key_tab, KEY_UP, &up_event);
	ft_addkey(*key_tab, KEY_NUM_8, &up_rot_x);
	ft_addkey(*key_tab, KEY_NUM_2, &down_rot_x);
	ft_addkey(*key_tab, KEY_NUM_6, &up_rot_y);
	ft_addkey(*key_tab, KEY_NUM_4, &down_rot_y);
	ft_addkey(*key_tab, KEY_NUM_3, &up_rot_z);
	ft_addkey(*key_tab, KEY_NUM_9, &down_rot_z);
	ft_addkey(*key_tab, KEY_PLUS, &up_c_scale);
	ft_addkey(*key_tab, KEY_MINUS, &down_c_scale);
	ft_addkey(*key_tab, KEY_PAGE_UP, &up_cz_scale);
	ft_addkey(*key_tab, KEY_PAGE_DOWN, &down_cz_scale);
}

t_key			**ft_get_key(int flag)
{
	static t_key	**key_tab = NULL;

	if (flag == 1)
		return (key_tab);
	if (flag == -1)
	{
		ft_del_key(&key_tab);
		return (NULL);
	}
	ft_initkey(&key_tab);
	return (key_tab);
}
